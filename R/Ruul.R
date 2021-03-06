#' Scale the matrix of data
#' 
#' @param x the matrix of data
#' @param scale the option to scale the matrix of data \cr
#' - case 0: unchanged \cr
#' - case 1: zero-mean normalization \cr
#' - case 2: Min-Max normalization \cr
#' - case 3: non-liner normalization \cr
#' @useDynLib Ruul
#' @export 
#' @examples
#' x <- matrix(c(1.24,1.72, 1.36,1.74, 1.38,1.64), 
#'      nrow = 3, ncol = 2, byrow = TRUE)
#' xstd <- Ruul_scale(x, scale = 1)
#' xstd
Ruul_scale <- function (x, scale = 1) {
    if (! is.matrix(x)) {
        stop("ERROR! Please input x as matrix.")
    } else if (any(is.na(x))) {
        stop("ERROR! Any elements in x must be not NA.")
    }

    scale <- as.integer(scale);
    if (is.na(scale)) {
        stop("ERROR! scale must be not NA.")
    } else if (scale > 3 || scale < 0) {
        stop("ERROR! scale must be 0, 1, ..., 3.")
    }

    .Call("Ruul__scale", x, scale, PACKAGE = "Ruul")
}

#' Distance the matrix of data
#' 
#' @param xstd the standard matrix of data
#' @param dist the option to distance the matrix of data \cr
#' - case 1: scalar product similarity \cr
#' - case 2: cosine similarity \cr 
#' - case 3: correlation coefficient similarity \cr
#' - case 4: correlation exponent coefficient similarity \cr
#' - case 5: Max-Min similarity \cr
#' - case 6: arithmetic average minimum similarity \cr
#' - case 7: geometry average minimum similarity \cr
#' - case 8: Euclidean distance similarity \cr
#' - case 9: Hamming distance similarity \cr
#' - case 10: Chebyshev distance similarity \cr
#' - case 11: Euclidean reciprocal distance similarity \cr
#' - case 12: Hamming reciprocal distance similarity \cr
#' - case 13: Chebyshev reciprocal distance similarity \cr
#' - case 14: Euclidean exponent distance similarity \cr
#' - case 15: Hamming exponent distance similarity \cr
#' - case 16: Chebyshev exponent distance similarity \cr
#' @useDynLib Ruul
#' @export 
#' @examples
#' xstd <- matrix(c(1.00,0.81,0.79, 0.81,1.00,0.82, 0.79,0.82,1.00), 
#'      nrow = 3, ncol = 3, byrow = TRUE)
#' r <- Ruul_dist(xstd, dist = 1)
#' r
Ruul_dist <- function (xstd, dist = 1) {
    if (! is.matrix(xstd)) {
        stop("ERROR! Please input xstd as matrix.")
    } else if (any(is.na(xstd))) {
        stop("ERROR! Any elements in xstd must be not NA.")
    }

    dist <- as.integer(dist)
    if (is.na(dist)) {
        stop("ERROR! dist must not be NA")
    } else if (dist > 16 || dist < 1) {
        stop("ERROR! dist must be 1, 2, ..., 16.")
    }

    .Call("Ruul__dist", xstd, dist, PACKAGE = "Ruul")
}

## Bind the matrix of relation
## 
## @param r1 the matrix of relation
## @param r2 the matrix of relation
## @export
## @useDynLib Ruul
## @examples
## r1 <- matrix(c(1.00,0.69,0.68, 0.69,1.00,0.69, 0.68,0.69,1.00),
##      nrow = 3, ncol = 3, byrow = TRUE)
## r2 <- matrix(c(1.00,0.76,0.78, 0.76,1.00,0.84, 0.78,0.84,1.00), 
##      nrow = 3, ncol = 3, byrow = TRUE)
## rt <- Ruul_bind(r1, r2)
## rt
Ruul_bind <- function (r1, r2) {
    if (! is.matrix(r1)) {
        stop("ERROR! Please input r1 as matrix.")
    } else if (any(is.na(r1))) {
        stop("ERROR! Any elements in r1 must be not NA.")
    }

    if (! is.matrix(r2)) {
        stop("ERROR! Please input r2 as matrix.")
    } else if (any(is.na(r2))) {
        stop("ERROR! Any elements in r2 must be not NA.")
    }

    .Call("Ruul__bind", r1, r2, PACKAGE = "Ruul")
}

#' Closure the matrix of relation
#' 
#' @param r the matrix of relation
#' @useDynLib Ruul
#' @export 
#' @examples
#' r <- matrix(c(1.00,0.69,0.68, 0.69,1.00,0.69, 0.68,0.69,1.00), 
#'      nrow = 3, ncol = 3, byrow = TRUE)
#' rt <- Ruul_closure(r)
#' rt
Ruul_closure <- function(r) {
    if (! is.matrix(r)) {
        stop("ERROR! Please input r as matrix.")
    } else if (any(is.na(r))) {
        stop("ERROR! Any elements in r must be not NA.")
    }

    rt <- Ruul_bind(r, r)
    while (! all(abs(r - rt) < 1E-6)) {  
        r  <- rt
        rt <- Ruul_bind(r, r)
    }

    return(rt)
}

