#ifndef RSTDAFX_H
#define RSTDAFX_H

#include <Rcpp.h>
#include "stdafx.h"

void RCopy(Rcpp::NumericMatrix M, PMatrix m);
void RCopy(PMatrix m, Rcpp::NumericMatrix M);

#endif /*!Rstdafx.h*/
