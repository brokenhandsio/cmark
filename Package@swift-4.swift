// swift-tools-version:4.0

import PackageDescription

let package = Package(
    name: "cmark",
    products: [
        .library(name: "cmark", targets: ["cmark"]),
    ],
    targets: [
        .target(name: "cmark")
    ]
)

