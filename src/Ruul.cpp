#include "uul.h"
#include "Ruul.h"

// [[Rcpp::export]]
SEXP Ruul::RScale(SEXP _X, SEXP _OPT)
{
    Rcpp::NumericMatrix X(_X);
    Rcpp::NumericMatrix XSTD(X.nrow(), X.ncol());

    Matrix x, xstd;
    PMatrix px = &x, pxstd = &xstd;
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

// [[Rcpp::export]]
SEXP Ruul::RDist(SEXP _X, SEXP _OPT)
{
    Rcpp::NumericMatrix X(_X);
    Rcpp::NumericMatrix R(X.nrow(), X.nrow());

    Matrix x, r;
    PMatrix px = &x, pr = &r;
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

// [[Rcpp::export]]
SEXP Ruul::RBind(SEXP _R1, SEXP _R2)
{
    Rcpp::NumericMatrix R1(_R1);
    Rcpp::NumericMatrix R2(_R2);
    Rcpp::NumericMatrix RT(R1.nrow(), R2.ncol());
 
    Matrix r1, r2, rt;
    PMatrix pr1 = &r1, pr2 = &r2, prt = &rt;

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
