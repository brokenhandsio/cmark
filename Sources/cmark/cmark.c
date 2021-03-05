#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "registry.h"
#include "node.h"
#include "houdini.h"
#include "cmark-gfm.h"
#include "buffer.h"
// Required for GRM cmark function
#include "autolink.h"
#include "strikethrough.h"
#include "table.h"
#include "tagfilter.h"
#include "tasklist.h"
#include "parser.h"

cmark_node_type CMARK_NODE_LAST_BLOCK = CMARK_NODE_FOOTNOTE_DEFINITION;
cmark_node_type CMARK_NODE_LAST_INLINE = CMARK_NODE_FOOTNOTE_REFERENCE;

int cmark_version() { return CMARK_GFM_VERSION; }

const char *cmark_version_string() { return CMARK_GFM_VERSION_STRING; }

static void *xcalloc(size_t nmem, size_t size) {
  void *ptr = calloc(nmem, size);
  if (!ptr) {
    fprintf(stderr, "[cmark] calloc returned null pointer, aborting\n");
    abort();
  }
  return ptr;
}

static void *xrealloc(void *ptr, size_t size) {
  void *new_ptr = realloc(ptr, size);
  if (!new_ptr) {
    fprintf(stderr, "[cmark] realloc returned null pointer, aborting\n");
    abort();
  }
  return new_ptr;
}

static void xfree(void *ptr) {
  free(ptr);
}

cmark_mem CMARK_DEFAULT_MEM_ALLOCATOR = {xcalloc, xrealloc, xfree};

cmark_mem *cmark_get_default_mem_allocator() {
  return &CMARK_DEFAULT_MEM_ALLOCATOR;
}

char *cmark_markdown_to_html(const char *text, size_t len, int options) {
  cmark_node *doc;
  char *result;

  doc = cmark_parse_document(text, len, options);

  result = cmark_render_html(doc, options, NULL);
  cmark_node_free(doc);

  return result;
}

char *cmark_gfm_markdown_to_html(const char *text, size_t len, int options) {
  cmark_node *doc = NULL;
  cmark_parser *parser = NULL;
  char *result;

  // Create a new parser we control
  parser = cmark_parser_new_with_mem(options, cmark_get_arena_mem_allocator());
  // Manually register the extensions
  cmark_parser_attach_syntax_extension(parser, create_autolink_extension());
  cmark_parser_attach_syntax_extension(parser, create_strikethrough_extension());
  cmark_parser_attach_syntax_extension(parser, create_table_extension());
  cmark_parser_attach_syntax_extension(parser, create_tagfilter_extension());
  cmark_parser_attach_syntax_extension(parser, create_tasklist_extension());

  cmark_parser_feed(parser, text, len);
  doc = cmark_parser_finish(parser);

  cmark_mem *mem = cmark_get_default_mem_allocator();
  result = cmark_render_html_with_mem(doc, options, parser->syntax_extensions, mem);
  cmark_parser_free(parser);
  cmark_node_free(doc);
  cmark_release_plugins();

  // This is not freed - it's up to the caller to release the memory
  return result;
}
