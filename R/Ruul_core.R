Ruul.stdm <- function (x, opt = 1) {
    .Call("RMatrixStandard", x, opt, PACKAGE = "Ruul")
}

Ruul.simm <- function (x, opt = 1) {
    .Call("RMatrixSimilar", x, opt, PACKAGE = "Ruul")
}

Ruul.comm <- function (r1, r2) {
    .Call("RMatrixComposite", r1, r2, PACKAGE = "Ruul")
}

Ruul.gseq <- function (from = 1, to, by = 1) {
    if (from <= to) {
        seq(from = from, to = to, by = by)
    } else {
        NULL
    }
}
