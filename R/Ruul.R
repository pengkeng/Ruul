Ruul <- function(x, stdopt = 0, simopt = 1) {
    if (! requireNamespace("Rcpp", quietly = TRUE)) {
        stop("Please install Rcpp: install.packages('Rcpp')")
    }

    if (stdopt > 3 || stdopt < 0) {
        stop("ERROR! stdopt must be 0, 1, ..., 3.")
    }
    if (simopt > 16 || simopt < 1) {
        stop("ERROR! simopt must be 1, 2, ..., 16.")
    }

    xstd <- Ruul.stdm(x,    opt = stdopt)
    rt   <- Ruul.simm(xstd, opt = simopt)
    Ruul.fdcp(rt)
}
