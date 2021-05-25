// swift-tools-version:5.2
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription


let package = Package(
    name: "XebUtils",
    products: [
        .library(name: "XebUtils", targets: ["XebUtils"]),
    ],
    targets: [
        .target(name: "XebUtils"),
    ]
)
