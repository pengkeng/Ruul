#ifndef RUUL_H
#define RUUL_H

#include "stdafx.h"
#include "Rstdafx.h"

RcppExport SEXP Ruul__scale (SEXP X, SEXP OPT);
RcppExport SEXP Ruul__dist (SEXP X, SEXP OPT);
RcppExport SEXP Ruul__bind (SEXP R1, SEXP R2);

#endif /*!Ruul.h*/

