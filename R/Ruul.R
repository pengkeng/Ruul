Ruul <- function(x, scale = 0, dist = 1) {
    if (! requireNamespace("Rcpp", quietly = TRUE)) {
        stop("Please install Rcpp: install.packages('Rcpp')")
    }

    if (! is.matrix(x)) {
        stop("Please input x as matrix.")
    }
    if (! is.numeric(scale)) {
        stop("Please input scale as numeric.")
    }
    if (! is.numeric(dist)) {
        stop("Please input dist as numeric.")
    }

    if (scale > 3 || scale < 0) {
        stop("ERROR! scale must be 0, 1, ..., 3.")
    }
    if (dist > 16 || dist < 1) {
        stop("ERROR! dist must be 1, 2, ..., 16.")
    }

    xstd <- Ruul.scale(x, scale)

    r <- Ruul.dist(xstd, dist)

    rt <- Ruul.bind(r, r)
    while (! all(abs(r - rt) < 1E-4)) {  
        r  <- rt
        rt <- Ruul.bind(r, r)
    }

    as.dist(r)
}
