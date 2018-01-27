#include "uul.h"
#include "Ruul.h"

void RCopy(Rcpp::NumericMatrix M, MatrixP m)
{
    for (Integer i = 0; i < M.nrow(); i++) 
        for (Integer j = 0; j < M.ncol(); j++)
            M(i, j) = *(*(m->ptr + i) + j);
}

void RCopy(MatrixP m, Rcpp::NumericMatrix M)
{
    for (Integer i = 0; i < m->nrow; i++) 
        for (Integer j = 0; j < m->ncol; j++)
            *(*(m->ptr + i) + j) = M(i, j);
}

// [[export]]
SEXP RScale(SEXP _X, SEXP _OPT)
{
    Rcpp::NumericMatrix X(_X);
    Rcpp::NumericMatrix XSTD(X.nrow(), X.ncol());

    Matrix x, xstd;
    MatrixP px = &x, pxstd = &xstd;
    Integer opt = Rcpp::as<Integer> (_OPT);

    Create(px, X.nrow(), X.ncol());
    Create(pxstd, XSTD.nrow(), XSTD.ncol());

    RCopy(px, X);

    Scale(pxstd, px, opt);

    RCopy(XSTD, pxstd);

    Destroy(px);
    Destroy(pxstd);

    return XSTD;
}

// [[export]]
SEXP RDist(SEXP _X, SEXP _OPT)
{
    Rcpp::NumericMatrix X(_X);
    Rcpp::NumericMatrix R(X.nrow(), X.nrow());

    Matrix x, r;
    MatrixP px = &x, pr = &r;
    Integer opt = Rcpp::as<Integer>(_OPT);

    Create(px, X.nrow(), X.ncol());
    Create(pr, R.nrow(), R.ncol());

    RCopy(px, X);

    Dist(pr, px, opt);

    RCopy(R, pr);

    Destroy(px);
    Destroy(pr);

    return R;
}

// [[export]]
SEXP RBind(SEXP _R1, SEXP _R2)
{
    Rcpp::NumericMatrix R1(_R1);
    Rcpp::NumericMatrix R2(_R2);
    Rcpp::NumericMatrix RT(R1.nrow(), R2.ncol());
 
    Matrix r1, r2, rt;
    MatrixP pr1 = &r1, pr2 = &r2, prt = &rt;

    Create(pr1, R1.nrow(), R1.ncol());
    Create(pr2, R2.nrow(), R2.ncol());

    RCopy(pr1, R1);
    RCopy(pr2, R2);

    Create(prt, RT.nrow(), RT.ncol());

    Bind(prt, pr1, pr2);

    RCopy(RT, prt);

    Destroy(pr1);
    Destroy(pr2);
    Destroy(prt);

    return RT;
}
