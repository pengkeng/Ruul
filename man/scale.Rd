\name{Ruul.scale}
\alias{Ruul.scale}
\title{
    Scale the matrix of data
}
\description{
    Scale the matrix of data.
}
\usage{
Ruul.scale(x, scale = 1)
}
\arguments{
    \item{x}{
        the matrix of data.
    }
    \item{scale}{
        the option to scale the matrix of data.

        case 0: unchanged

        case 1: zero-mean normalization

        case 2: Min-Max normalization

        case 3: non-liner normalization
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
r <- Ruul.dist(xstd, dist = 12)
rt <- Ruul.closure(r)
d <- as.dist(rt)
hc <- hclust(d)
plot(hc, hang = -1)
}
