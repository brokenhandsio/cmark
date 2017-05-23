# cmark (Github Flavoured Markdown)

[![Build Status](https://travis-ci.org/brokenhandsio/cmark-gfm.svg?branch=master)](https://travis-ci.org/brokenhandsio/cmark-gfm)

`cmark-gfm` is an SPM-compatible fork of Github's implementation of the [CommonMark library](http://commonmark.org/). Github's fork adds GitHub Flavoured Markdown extensions to
[the upstream implementation](https://github.com/jgm/cmark), as defined in [the spec](https://github.github.com/gfm/).

For more information, see the [Github `cmark` repository](https://github.com/github/cmark/).

---

# Building

To build this repository, just run:

```bash
swift build
```

# Using

To use this repository, add it to your `Package.swift` file:

```swift
dependencies: [
    ...,
    .Package(url: "https://github.com/brokenhandsio/cmark-gfm", majorVersion: 1)
]
```
