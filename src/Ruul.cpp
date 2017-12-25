#include "uul.h"
#include "Ruul.hpp"

// [[Rcpp::export]]
SEXP RMatrixStandard(SEXP _X, SEXP _OPT)
{
    NumericMatrix X(_X);
    int opt = as<int> (_OPT);
    NumericMatrix XSTD(X.nrow(), X.ncol());

    _Matrix x, xstd;
    _PMatrix px = &x, pxstd = &xstd;

    matrixCreate(px, X.nrow(), X.ncol());
    matrixCreate(pxstd, XSTD.nrow(), XSTD.ncol());

    RMatrixCopy(px, X);

    matrixStandard(pxstd, px, opt);

    RMatrixCopy(XSTD, pxstd);

    matrixDestroy(px);
    matrixDestroy(pxstd);

    return XSTD;
}

// [[Rcpp::export]]
SEXP RMatrixSimilar(SEXP _X, SEXP _OPT)
{
    NumericMatrix X(_X);
    int opt = as<int>(_OPT);
    NumericMatrix R(X.nrow(), X.nrow());

    _Matrix x, r;
    _PMatrix px = &x, pr = &r;

    matrixCreate(px, X.nrow(), X.ncol());
    matrixCreate(pr, R.nrow(), R.ncol());

    RMatrixCopy(px, X);

    matrixSimilar(pr, px, opt);

    RMatrixCopy(R, pr);

    matrixDestroy(px);
    matrixDestroy(pr);

    return R;
}

// [[Rcpp::export]]
SEXP RMatrixComposite(SEXP _R1, SEXP _R2)
{
    NumericMatrix R1(_R1);
    NumericMatrix R2(_R2);
    NumericMatrix RT(R1.nrow(), R2.ncol());
 
    _Matrix r1, r2, rt;
    _PMatrix pr1 = &r1, pr2 = &r2, prt = &rt;

    matrixCreate(pr1, R1.nrow(), R1.ncol());
    matrixCreate(pr2, R2.nrow(), R2.ncol());
    matrixCreate(prt, RT.nrow(), RT.ncol());

    RMatrixCopy(pr1, R1);
    RMatrixCopy(pr2, R2);

    matrixComposite(prt, pr1, pr2);

    RMatrixCopy(RT, prt);

    matrixDestroy(pr1);
    matrixDestroy(pr2);
    matrixDestroy(prt);

    return RT;
}
