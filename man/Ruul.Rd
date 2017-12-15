\name{Ruul}
\alias{Ruul}
\title{
    Fuzzy Dynamtic Clustering Picture Maker
}
\usage{
    Ruul(x, stdopt = 0, simopt = 1)
}
\arguments{
    \item{x}{
        the matrix of data.}
    \item{stdopt}{
        the style to create standard matrix.

        case 0: unchanged

        case 1: zero-mean normalization

        case 2: Min-Max normalization

        case 3: non-liner normalization
    }
    \item{simopt}{
        the style to create similar matrix.

        case 1: scalar product similarity

        case 2: cosine similarity

        case 3: correlation coefficient similarity

        case 4: correlation exponent coefficient similarity

        case 5: Max-Min similarity

        case 6: arithmetic average minimum similarity

        case 7: geometry average minimum similarity

        case 8: Euclidean distance similarity

        case 9: Hamming distance similarity

        case 10: Chebyshev distance similarity

        case 11: Euclidean reciprocal distance similarity

        case 12: Hamming reciprocal distance similarity

        case 13: Chebyshev reciprocal distance similarity

        case 14: Euclidean exponent distance similarity

        case 15: Hamming exponent distance similarity

        case 16: Chebyshev exponent distance similarity}
}
\description{
    Fuzzy Dynamtic Clustering Picture Maker.
}
\examples{
x <- matrix( c( 1.24,1.72, 
                1.36,1.74, 
                1.38,1.64, 
                1.38,1.82, 
                1.38,1.90, 
                1.40,1.70, 
                1.48,1.82, 
                1.54,1.82, 
                1.56,2.08, 
                1.14,1.78 ), 
             ncol = 2, byrow = TRUE )
Ruul(x, stdopt = 1, simopt = 3)
}
