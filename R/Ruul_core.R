Ruul.scale <- function (x, scale = 1) {
    .Call("RScale", x, scale, PACKAGE = "Ruul")
}

Ruul.dist <- function (x, dist = 1) {
    .Call("RDist", x, dist, PACKAGE = "Ruul")
}

Ruul.bind <- function (r1, r2) {
    .Call("RBind", r1, r2, PACKAGE = "Ruul")
}

