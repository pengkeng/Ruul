#include "Rstdafx.h"

void RMatrixCopy(NumericMatrix M, _PMatrix m)
{
    for (_Integer i = 0; i < M.nrow(); i++) 
        for (_Integer j = 0; j < M.ncol(); j++)
            M(i, j) = *(*(m->ptr + i) + j);
}

void RMatrixCopy(_PMatrix m, NumericMatrix M)
{
    for (_Integer i = 0; i < m->nrow; i++) 
        for (_Integer j = 0; j < m->ncol; j++)
            *(*(m->ptr + i) + j) = M(i, j);
}


