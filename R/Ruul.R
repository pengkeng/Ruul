Ruul.scale <- function (x, scale = 1) {
    if (! requireNamespace("Rcpp", quietly = TRUE)) {
        stop("Please install Rcpp: install.packages('Rcpp')")
    }
    if (! is.matrix(x)) {
        stop("Please input x as matrix.")
    }
    if (! is.numeric(scale)) {
        stop("Please input scale as numeric.")
    }
    if (scale > 3 || scale < 0) {
        stop("ERROR! scale must be 0, 1, ..., 3.")
    }

    .Call("R_scale", x, scale, PACKAGE = "Ruul")
}

Ruul.dist <- function (xstd, dist = 1) {
    if (! requireNamespace("Rcpp", quietly = TRUE)) {
        stop("Please install Rcpp: install.packages('Rcpp')")
    }
    if (! is.matrix(xstd)) {
        stop("Please input x as matrix.")
    }
    if (! is.numeric(dist)) {
        stop("Please input dist as numeric.")
    }
    if (dist > 16 || dist < 1) {
        stop("ERROR! dist must be 1, 2, ..., 16.")
    }

    .Call("R_dist", xstd, dist, PACKAGE = "Ruul")
}

Ruul.bind <- function (r1, r2) {
    if (! requireNamespace("Rcpp", quietly = TRUE)) {
        stop("Please install Rcpp: install.packages('Rcpp')")
    }
    if (! is.matrix(r1)) {
        stop("Please input r1 as matrix.")
    }
    if (! is.matrix(r2)) {
        stop("Please input r2 as matrix.")
    }

    .Call("R_bind", r1, r2, PACKAGE = "Ruul")
}

Ruul.closure <- function(r) {
    if (! is.matrix(r)) {
        stop("Please input r as matrix.")
    }

    rt <- Ruul.bind(r, r)
    while (! all(abs(r - rt) < 1E-4)) {  
        r  <- rt
        rt <- Ruul.bind(r, r)
    }

    return(rt)
}

