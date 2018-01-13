#include "Rstdafx.h"

void RCopy(Rcpp::NumericMatrix M, PMatrix m)
{
    for (Integer i = 0; i < M.nrow(); i++) 
        for (Integer j = 0; j < M.ncol(); j++)
            M(i, j) = *(*(m->ptr + i) + j);
}

void RCopy(PMatrix m, Rcpp::NumericMatrix M)
{
    for (Integer i = 0; i < m->nrow; i++) 
        for (Integer j = 0; j < m->ncol; j++)
            *(*(m->ptr + i) + j) = M(i, j);
}
