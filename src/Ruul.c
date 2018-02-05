#include "uul.h"
#include "Ruul.h"

// [[export]]
SEXP Ruul__scale (SEXP _X, SEXP _OPT)
{
    SEXP _Xstd = Rf_allocMatrix (REALSXP, Rf_nrows(_X), Rf_ncols(_X));

    uul__Matrix  X,       Xstd;
    uul__MatrixP pX = &X, pXstd = &Xstd;
    uul__Integer opt = INTEGER(_OPT)[0];

    pX->ptr = REAL(_X),       pX->nrow = Rf_nrows(_X),       pX->ncol = Rf_ncols(_X);
    pXstd->ptr = REAL(_Xstd), pXstd->nrow = Rf_nrows(_Xstd), pXstd->ncol = Rf_ncols(_Xstd);

    uul__scale (pXstd, pX, opt);

    return _Xstd;
}

// [[export]]
SEXP Ruul__dist (SEXP _X, SEXP _OPT)
{
    SEXP _R = Rf_allocMatrix (REALSXP, Rf_nrows(_X), Rf_nrows(_X));

    uul__Matrix  X,       R;
    uul__MatrixP pX = &X, pR = &R;
    uul__Integer opt = INTEGER(_OPT)[0];

    pX->ptr = REAL(_X), pX->nrow = Rf_nrows(_X), pX->ncol = Rf_ncols(_X);
    pR->ptr = REAL(_R), pR->nrow = Rf_nrows(_R), pR->ncol = Rf_ncols(_R);

    uul__dist (pR, pX, opt);

    return _R;
}

// [[export]]
SEXP Ruul__bind (SEXP _R1, SEXP _R2)
{
    SEXP _Rt = Rf_allocMatrix (REALSXP, Rf_nrows(_R1), Rf_nrows(_R2));

    uul__Matrix  R1,        R2,        Rt;
    uul__MatrixP pR1 = &R1, pR2 = &R2, pRt = &Rt;

    pR1->ptr = REAL(_R1), pR1->nrow = Rf_nrows(_R1), pR1->ncol = Rf_ncols(_R1);
    pR2->ptr = REAL(_R2), pR2->nrow = Rf_nrows(_R2), pR2->ncol = Rf_ncols(_R2);
    pRt->ptr = REAL(_Rt), pRt->nrow = Rf_nrows(_Rt), pRt->ncol = Rf_ncols(_Rt);

    uul__bind (pRt, pR1, pR2);

    return _Rt;
}

