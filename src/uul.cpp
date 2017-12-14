#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "uul.h"

_Status matrixCreate (_Matrix &M, _Integer nrow, _Integer ncol)
{
    if (nrow <= 0 || ncol <= 0) {
        return _ERROR_;
    }

    M.nrow = nrow;
    M.ncol = ncol;

    M.ptr = (_ElemType **) malloc (sizeof (_ElemType *) * M.nrow);
    if (M.ptr == NULL) {
        return _OVERFLOW_;
    }

    for (_Integer i = 0; i < M.nrow; i++) {
        *(M.ptr + i) = (_ElemType *)calloc(M.ncol, sizeof (_ElemType));
        if (*(M.ptr + i) == NULL) {
            return _OVERFLOW_;
        }
    }

    return _SUCCESS_;
}

_Status matrixDestroy (_Matrix &M)
{
    for (_Integer i = 0; i < M.nrow; i++) {
        free (*(M.ptr + i));
        if (*(M.ptr + i) == NULL) {
            return _OVERFLOW_;
        }
    }
    free (M.ptr);
    if (M.ptr == NULL) {
        return _OVERFLOW_;
    }

    return _SUCCESS_;
}

