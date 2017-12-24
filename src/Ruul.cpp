#include <stdlib.h>
#include "uul.h"
#include "Ruul.h"

using namespace Rcpp;

// [[Rcpp::export]]
SEXP RMatrixStandard(SEXP _X, SEXP _OPT)
{
    NumericMatrix X(_X);
    int opt = as<int> (_OPT);
    NumericMatrix XSTD(X.nrow(), X.ncol());

    _PMatrix x, xstd;

    x = (_PMatrix) malloc (sizeof (_Matrix));
    xstd = (_PMatrix) malloc (sizeof (_Matrix));

    matrixCreate(x, X.nrow(), X.ncol());
    matrixCreate(xstd, XSTD.nrow(), XSTD.ncol());

    for (int i = 0; i < x->nrow; i++)
        for (int j = 0; j < x->ncol; j++)
            *(*(x->ptr + i) + j) = X(i, j);

    matrixStandard(xstd, x, opt);

    for (int i = 0; i < XSTD.nrow(); i++)
        for (int j = 0; j < XSTD.ncol(); j++)
            XSTD(i, j) = *(*(xstd->ptr + i) + j);

    matrixDestroy(x);
    matrixDestroy(xstd);

    free(x);
    free(xstd);

    return XSTD;
}

// [[Rcpp::export]]
SEXP RMatrixSimilar(SEXP _X, SEXP _OPT)
{
    NumericMatrix X(_X);
    int opt = as<int>(_OPT);
    NumericMatrix R(X.nrow(), X.nrow());

    _PMatrix x, r;

    x = (_PMatrix) malloc (sizeof (_Matrix));
    r = (_PMatrix) malloc (sizeof (_Matrix));

    matrixCreate(x, X.nrow(), X.ncol());
    matrixCreate(r, R.nrow(), R.ncol());

    for (int i = 0; i < x->nrow; i++)
        for (int j = 0; j < x->ncol; j++)
            *(*(x->ptr + i) + j) = X(i, j);

    matrixSimilar(r, x, opt);

    for (int i = 0; i < R.nrow(); i++)
        for (int j = 0; j < R.ncol(); j++)
            R(i, j) = *(*(r->ptr + i) + j);

    matrixDestroy(x);
    matrixDestroy(r);

    free(x);
    free(r);

    return R;
}

// [[Rcpp::export]]
SEXP RMatrixComposite(SEXP _R1, SEXP _R2)
{
    NumericMatrix R1(_R1);
    NumericMatrix R2(_R2);
    NumericMatrix RT(R1.nrow(), R2.ncol());
 
    _PMatrix r1, r2, rt;

    r1 = (_PMatrix) malloc (sizeof (_Matrix));
    r2 = (_PMatrix) malloc (sizeof (_Matrix));
    rt = (_PMatrix) malloc (sizeof (_Matrix));

    matrixCreate(r1, R1.nrow(), R1.ncol());
    matrixCreate(r2, R2.nrow(), R2.ncol());
    matrixCreate(rt, RT.nrow(), RT.ncol());

    for (int i = 0; i < r1->nrow; i++)
        for (int j = 0; j < r1->ncol; j++) 
            *(*(r1->ptr + i) + j) = R1(i, j);

    for (int i = 0; i < r2->nrow; i++)
        for (int j = 0; j < r2->ncol; j++) 
            *(*(r2->ptr + i) + j) = R2(i, j);

    matrixComposite(rt, r1, r2);

    for (int i = 0; i < RT.nrow(); i++)
        for (int j = 0; j < RT.ncol(); j++)
            RT(i, j) = *(*(rt->ptr + i) + j);

    matrixDestroy(r1);
    matrixDestroy(r2);
    matrixDestroy(rt);

    free(r1);
    free(r2);
    free(rt);

    return RT;
}
