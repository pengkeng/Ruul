#ifndef RUUL_H
#define RUUL_H

#include <R.h>
#include <Rinternals.h>

extern SEXP Ruul__scale (SEXP X, SEXP OPT);
extern SEXP Ruul__dist (SEXP X, SEXP OPT);
extern SEXP Ruul__bind (SEXP R1, SEXP R2);

#endif /* Ruul.h */

