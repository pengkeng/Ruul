#include "uul.h"
#include "Ruul.h"

// [[export]]
SEXP Ruul__scale (SEXP _X, SEXP _OPT)
{
    SEXP _Xstd = Rf_allocMatrix (REALSXP, Rf_nrows(_X), Rf_ncols(_X));

    uul__MatrixP  X,       Xstd;
    uul__Integer opt = INTEGER(_OPT)[0];

    X = (uul__MatrixP) malloc (sizeof (uul__Matrix));
    Xstd = (uul__MatrixP) malloc (sizeof (uul__Matrix));

    X->ptr = REAL(_X),       X->nrow = Rf_nrows(_X),       X->ncol = Rf_ncols(_X);
    Xstd->ptr = REAL(_Xstd), Xstd->nrow = Rf_nrows(_Xstd), Xstd->ncol = Rf_ncols(_Xstd);

    uul__scale (Xstd, X, opt);

    free (X);
    free (Xstd);

    return _Xstd;
}

// [[export]]
SEXP Ruul__dist (SEXP _X, SEXP _OPT)
{
    SEXP _R = Rf_allocMatrix (REALSXP, Rf_nrows(_X), Rf_nrows(_X));

    uul__MatrixP  X,       R;
    uul__Integer opt = INTEGER(_OPT)[0];

    X = (uul__MatrixP) malloc (sizeof (uul__Matrix));
    R = (uul__MatrixP) malloc (sizeof (uul__Matrix));

    X->ptr = REAL(_X), X->nrow = Rf_nrows(_X), X->ncol = Rf_ncols(_X);
    R->ptr = REAL(_R), R->nrow = Rf_nrows(_R), R->ncol = Rf_ncols(_R);

    uul__dist (R, X, opt);

    free (R);
    free (X);

    return _R;
}

// [[export]]
SEXP Ruul__bind (SEXP _R1, SEXP _R2)
{
    SEXP _Rt = Rf_allocMatrix (REALSXP, Rf_nrows(_R1), Rf_nrows(_R2));

    uul__MatrixP R1, R2, Rt;

    R1 = (uul__MatrixP) malloc (sizeof (uul__Matrix));
    R2 = (uul__MatrixP) malloc (sizeof (uul__Matrix));
    Rt = (uul__MatrixP) malloc (sizeof (uul__Matrix));

    R1->ptr = REAL(_R1), R1->nrow = Rf_nrows(_R1), R1->ncol = Rf_ncols(_R1);
    R2->ptr = REAL(_R2), R2->nrow = Rf_nrows(_R2), R2->ncol = Rf_ncols(_R2);
    Rt->ptr = REAL(_Rt), Rt->nrow = Rf_nrows(_Rt), Rt->ncol = Rf_ncols(_Rt);

    uul__bind (Rt, R1, R2);

    free (Rt);
    free (R1);
    free (R2);

    return _Rt;
}

