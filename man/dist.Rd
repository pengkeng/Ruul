\name{Ruul.dist}
\alias{Ruul.dist}
\title{
    Distance the matrix of data
}
\usage{
Ruul.dist(xstd, dist = 1)
}
\description{
    Distance the matrix of data.
}
\arguments{
    \item{xstd}{
        the standard matrix of data.
    }
    \item{dist}{
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

        case 16: Chebyshev exponent distance similarity
    }
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
xstd <- Ruul.scale(x, scale = 1)
d <- Ruul.dist(xstd, dist = 12)
d <- as.dist(d)
hc <- hclust(d)
plot(hc, hang = -1)
}
