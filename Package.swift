// swift-tools-version:5.1

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
