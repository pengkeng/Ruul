Ruul.scale <- function (x, scale = 1) {
    .Call("RMatrixStandard", x, scale, PACKAGE = "Ruul")
}

Ruul.dist <- function (x, dist = 1) {
    .Call("RMatrixSimilar", x, dist, PACKAGE = "Ruul")
}

Ruul.bind <- function (r1, r2) {
    .Call("RMatrixComposite", r1, r2, PACKAGE = "Ruul")
}

Ruul.hclust <- function(d, method = "complete", members = NULL) {
    hclust(d, method, members)
}

