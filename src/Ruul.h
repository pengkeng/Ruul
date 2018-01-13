#ifndef RUUL_H
#define RUUL_H

#include "stdafx.h"
#include "Rstdafx.h"

namespace Ruul {
    RcppExport SEXP RScale(SEXP X, SEXP OPT);
    RcppExport SEXP RDist(SEXP X, SEXP OPT);
    RcppExport SEXP RBind(SEXP R1, SEXP R2);
};

#endif /*!Ruul.h*/

