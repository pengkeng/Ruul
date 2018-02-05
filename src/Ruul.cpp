#include "uul.h"
#include "Ruul.h"

void Ruul__copy (Rcpp::NumericMatrix X, uul__MatrixP x)
{
    for (uul__Integer i = 0; i < X.nrow(); i++) 
        for (uul__Integer j = 0; j < X.ncol(); j++)
            X(i, j) = *(*(x->ptr + i) + j);
}

void Ruul__copy (uul__MatrixP x, Rcpp::NumericMatrix X)
{
    for (uul__Integer i = 0; i < x->nrow; i++) 
        for (uul__Integer j = 0; j < x->ncol; j++)
            *(*(x->ptr + i) + j) = X(i, j);
}

// [[export]]
SEXP Ruul__scale (SEXP _X, SEXP _OPT)
{
    Rcpp::NumericMatrix X(_X);
    Rcpp::NumericMatrix XSTD(X.nrow(), X.ncol());

    uul__MatrixP x, xstd;
    uul__Integer opt = *INTEGER (_OPT);

    x = (uul__MatrixP) malloc (sizeof (uul__Matrix));
    xstd = (uul__MatrixP) malloc (sizeof (uul__Matrix));

    uul__create (x, X.nrow(), X.ncol());
    uul__create (xstd, XSTD.nrow(), XSTD.ncol());

    Ruul__copy (x, X);

    uul__scale (xstd, x, opt);

    Ruul__copy (XSTD, xstd);

    uul__destroy (x);
    uul__destroy (xstd);

    return XSTD;
}

// [[export]]
SEXP Ruul__dist (SEXP _X, SEXP _OPT)
{
    Rcpp::NumericMatrix X (_X);
    Rcpp::NumericMatrix R (X.nrow(), X.nrow());

    uul__MatrixP x, r;
    uul__Integer opt = *INTEGER (_OPT);

    x = (uul__MatrixP) malloc (sizeof (uul__Matrix));
    r = (uul__MatrixP) malloc (sizeof (uul__Matrix));

    uul__create (x, X.nrow(), X.ncol());
    uul__create (r, R.nrow(), R.ncol());

    Ruul__copy (x, X);

    uul__dist (r, x, opt);

    Ruul__copy (R, r);

    uul__destroy (x);
    uul__destroy (r);

    return R;
}

// [[export]]
SEXP Ruul__bind (SEXP _R1, SEXP _R2)
{
    Rcpp::NumericMatrix R1(_R1);
    Rcpp::NumericMatrix R2(_R2);
    Rcpp::NumericMatrix Rt(R1.nrow(), R2.ncol());
 
    uul__MatrixP r1, r2, rt;

    r1 = (uul__MatrixP) malloc (sizeof (uul__Matrix));
    r2 = (uul__MatrixP) malloc (sizeof (uul__Matrix));
    rt = (uul__MatrixP) malloc (sizeof (uul__Matrix));

    uul__create (r1, R1.nrow(), R1.ncol());
    uul__create (r2, R2.nrow(), R2.ncol());

    Ruul__copy (r1, R1);
    Ruul__copy (r2, R2);

    uul__create (rt, Rt.nrow(), Rt.ncol());

    uul__bind (rt, r1, r2);

    Ruul__copy (Rt, rt);

    uul__destroy (r1);
    uul__destroy (r2);
    uul__destroy (rt);

    return Rt;
}

