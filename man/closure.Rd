\name{Ruul.closure}
\alias{Ruul.closure}
\title{
    Closure the matrix of relation
}
\description{
    Closure the matrix of relation.
}
\usage{
Ruul.closure(r)
}
\arguments{
    \item{r}{
        the matrix of relation.
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
