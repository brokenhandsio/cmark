# cmark (Github Flavoured Markdown)

[![Language](https://img.shields.io/badge/Swift-5.1-brightgreen.svg)](http://swift.org)
[![Build Status](https://github.com/brokenhandsio/cmark-gfm/workflows/CI/badge.svg?branch=master)](https://github.com/brokenhandsio/cmark-gfm/actions)
[![GitHub license](https://img.shields.io/badge/license-BSD2-blue.svg)](https://raw.githubusercontent.com/brokenhandsio/cmark-gfm/master/COPYING)

`cmark-gfm` is an SwiftPM-compatible fork of Github's implementation of the [CommonMark library](http://commonmark.org/). Github's fork adds GitHub Flavoured Markdown extensions to
[the upstream implementation](https://github.com/jgm/cmark), as defined in [the spec](https://github.github.com/gfm/).

For more information, see the [Github `cmark` repository](https://github.com/github/cmark/).

---

# Building

To build this repository, just run:

```bash
swift build
```

# Using

To use this repository, add it to your `Package.swift` manifest:

```swift
dependencies: [
    ...,
    .package(url: "https://github.com/brokenhandsio/cmark-gfm.git", from: "2.0.0")
]
```
