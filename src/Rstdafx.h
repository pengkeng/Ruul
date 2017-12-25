#ifndef RSTDAFX_H
#define RSTDAFX_H

#include <Rcpp.h>
#include "stdafx.h"

using namespace Rcpp;

void RMatrixCopy(NumericMatrix M, _PMatrix m);
void RMatrixCopy(_PMatrix m, NumericMatrix M);

#endif /*!Rstdafx.h*/
