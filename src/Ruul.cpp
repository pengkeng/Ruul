#include "uul.h"
#include "Ruul.h"

using namespace Rcpp;

void R_copy(NumericMatrix X, uul__MatrixP x)
{
    for (int i = 0; i < X.nrow(); i++) 
        for (int j = 0; j < X.ncol(); j++)
            X(i, j) = *(*(x->ptr + i) + j);
}

void R_copy(uul__MatrixP x, NumericMatrix X)
{
    for (int i = 0; i < x->nrow; i++) 
        for (int j = 0; j < x->ncol; j++)
            *(*(x->ptr + i) + j) = X(i, j);
}

// [[export]]
SEXP R_scale(SEXP _X, SEXP _OPT)
{
    NumericMatrix X(_X);
    NumericMatrix XSTD(X.nrow(), X.ncol());

    uul__MatrixP x, xstd;
    int opt = as<int> (_OPT);

    x = (uul__MatrixP) malloc (sizeof (uul__Matrix));
    xstd = (uul__MatrixP) malloc (sizeof (uul__Matrix));

    uul__create(x, X.nrow(), X.ncol());
    uul__create(xstd, XSTD.nrow(), XSTD.ncol());

    R_copy(x, X);

    uul__scale(xstd, x, opt);

    R_copy(XSTD, xstd);

    uul__destroy(x);
    uul__destroy(xstd);

    return XSTD;
}

// [[export]]
SEXP R_dist(SEXP _X, SEXP _OPT)
{
    NumericMatrix X(_X);
    NumericMatrix R(X.nrow(), X.nrow());

    uul__MatrixP x, r;
    int opt = as<int> (_OPT);

    x = (uul__MatrixP) malloc (sizeof (uul__Matrix));
    r = (uul__MatrixP) malloc (sizeof (uul__Matrix));

    uul__create(x, X.nrow(), X.ncol());
    uul__create(r, R.nrow(), R.ncol());

    R_copy(x, X);

    uul__dist(r, x, opt);

    R_copy(R, r);

    uul__destroy(x);
    uul__destroy(r);

    return R;
}

// [[export]]
SEXP R_bind(SEXP _R1, SEXP _R2)
{
    NumericMatrix R1(_R1);
    NumericMatrix R2(_R2);
    NumericMatrix Rt(R1.nrow(), R2.ncol());
 
    uul__MatrixP r1, r2, rt;

    r1 = (uul__MatrixP) malloc (sizeof (uul__Matrix));
    r2 = (uul__MatrixP) malloc (sizeof (uul__Matrix));
    rt = (uul__MatrixP) malloc (sizeof (uul__Matrix));

    uul__create(r1, R1.nrow(), R1.ncol());
    uul__create(r2, R2.nrow(), R2.ncol());

    R_copy(r1, R1);
    R_copy(r2, R2);

    uul__create(rt, Rt.nrow(), Rt.ncol());

    uul__bind(rt, r1, r2);

    R_copy(Rt, rt);

    uul__destroy(r1);
    uul__destroy(r2);
    uul__destroy(rt);

    return Rt;
}

