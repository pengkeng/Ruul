#ifndef RUUL_H
#define RUUL_H

#include "stdafx.h"
#include "Rstdafx.hpp"

RcppExport SEXP RMatrixStandard(SEXP X, SEXP OPT);
RcppExport SEXP RMatrixSimilar(SEXP X, SEXP OPT);
RcppExport SEXP RMatrixComposite(SEXP R1, SEXP R2);

#endif /*!Ruul.h*/
