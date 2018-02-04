#ifndef RUUL_H
#define RUUL_H

#include "stdafx.h"
#include "Rstdafx.h"

RcppExport SEXP R_scale(SEXP X, SEXP OPT);
RcppExport SEXP R_dist(SEXP X, SEXP OPT);
RcppExport SEXP R_bind(SEXP R1, SEXP R2);

#endif /*!Ruul.h*/

