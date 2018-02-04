#include "uul.h"
#include "Ruul.h"

using namespace Rcpp;

void U2R_copy(NumericMatrix X, U_MatrixP x)
{
    for (U_Integer i = 0; i < X.nrow(); i++) 
        for (U_Integer j = 0; j < X.ncol(); j++)
            X(i, j) = *(*(x->ptr + i) + j);
}

void R2U_copy(U_MatrixP x, NumericMatrix X)
{
    for (U_Integer i = 0; i < x->nrow; i++) 
        for (U_Integer j = 0; j < x->ncol; j++)
            *(*(x->ptr + i) + j) = X(i, j);
}

// [[export]]
SEXP R_scale(SEXP _X, SEXP _OPT)
{
    NumericMatrix X(_X);
    NumericMatrix XSTD(X.nrow(), X.ncol());

    U_MatrixP x, xstd;
    U_Integer opt = as<U_Integer> (_OPT);

    x = (U_MatrixP) malloc (sizeof (U_Matrix));
    xstd = (U_MatrixP) malloc (sizeof (U_Matrix));

    U_create(x, X.nrow(), X.ncol());
    U_create(xstd, XSTD.nrow(), XSTD.ncol());

    R2U_copy(x, X);

    U_scale(xstd, x, opt);

    U2R_copy(XSTD, xstd);

    U_destroy(x);
    U_destroy(xstd);

    return XSTD;
}

// [[export]]
SEXP R_dist(SEXP _X, SEXP _OPT)
{
    NumericMatrix X(_X);
    NumericMatrix R(X.nrow(), X.nrow());

    U_MatrixP x, r;
    U_Integer opt = as<U_Integer> (_OPT);

    x = (U_MatrixP) malloc (sizeof (U_Matrix));
    r = (U_MatrixP) malloc (sizeof (U_Matrix));

    U_create(x, X.nrow(), X.ncol());
    U_create(r, R.nrow(), R.ncol());

    R2U_copy(x, X);

    U_dist(r, x, opt);

    U2R_copy(R, r);

    U_destroy(x);
    U_destroy(r);

    return R;
}

// [[export]]
SEXP R_bind(SEXP _R1, SEXP _R2)
{
    NumericMatrix R1(_R1);
    NumericMatrix R2(_R2);
    NumericMatrix RT(R1.nrow(), R2.ncol());
 
    U_MatrixP r1, r2, rt;

    r1 = (U_MatrixP) malloc (sizeof (U_Matrix));
    r2 = (U_MatrixP) malloc (sizeof (U_Matrix));
    rt = (U_MatrixP) malloc (sizeof (U_Matrix));

    U_create(r1, R1.nrow(), R1.ncol());
    U_create(r2, R2.nrow(), R2.ncol());

    R2U_copy(r1, R1);
    R2U_copy(r2, R2);

    U_create(rt, RT.nrow(), RT.ncol());

    U_bind(rt, r1, r2);

    U2R_copy(RT, rt);

    U_destroy(r1);
    U_destroy(r2);
    U_destroy(rt);

    return RT;
}

