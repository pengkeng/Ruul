#ifndef RUUL_H
#define RUUL_H

#include <Rcpp.h>

using namespace Rcpp;

RcppExport SEXP RMatrixStandard(SEXP X, SEXP OPT);
RcppExport SEXP RMatrixSimilar(SEXP X, SEXP OPT);
RcppExport SEXP RMatrixComposite(SEXP R1, SEXP R2);

#endif /*!Rcpp.h*/
