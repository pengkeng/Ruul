/**
 * @file Ruul.c
 * @Synopsis  模糊矩阵运算
 * @author Tokhta Horqin
 * @version 0.2.1
 * @date 2018-02-14
 */

#include <stdlib.h>
#include <Rinternals.h>
#include "uul.h"
#include "Ruul.h"

/* --------------------------------------------------------------------------*/
/**
 * @Synopsis  标准矩阵的创建
 *
 * @Param  _X 输入的数据矩阵
 * @Param  _OPT 标准矩阵创建的方法
 *
 * @Returns  创建的标准矩阵
 */
/* --------------------------------------------------------------------------*/
SEXP Ruul__scale (SEXP _X, SEXP _OPT)
{
    SEXP _Xstd = Rf_allocMatrix (REALSXP, Rf_nrows(_X), Rf_ncols(_X));

    uul__MatrixP  X,       Xstd;
    uul__Integer opt = INTEGER(_OPT)[0];

    X = (uul__MatrixP) malloc (sizeof (uul__Matrix));
    Xstd = (uul__MatrixP) malloc (sizeof (uul__Matrix));

    X->ptr = REAL(_X),       X->nrow = Rf_nrows(_X),       X->ncol = Rf_ncols(_X);
    Xstd->ptr = REAL(_Xstd), Xstd->nrow = Rf_nrows(_Xstd), Xstd->ncol = Rf_ncols(_Xstd);

    uul__Integer result = uul__scale (Xstd, X, opt);

    free (X);
    free (Xstd);

    if (result == UUL_ERROR)
        Rprintf ("scale failed!\n");
    
    return _Xstd;
}

/* --------------------------------------------------------------------------*/
/**
 * @Synopsis  相似矩阵的创建
 *
 * @Param  _X 输入的数据矩阵
 * @Param  _OPT 相似矩阵创建的方法
 *
 * @Returns  创建的相似矩阵
 */
/* --------------------------------------------------------------------------*/
SEXP Ruul__dist (SEXP _X, SEXP _OPT)
{
    SEXP _R = Rf_allocMatrix (REALSXP, Rf_nrows(_X), Rf_nrows(_X));

    uul__MatrixP  X,       R;
    uul__Integer opt = INTEGER(_OPT)[0];

    X = (uul__MatrixP) malloc (sizeof (uul__Matrix));
    R = (uul__MatrixP) malloc (sizeof (uul__Matrix));

    X->ptr = REAL(_X), X->nrow = Rf_nrows(_X), X->ncol = Rf_ncols(_X);
    R->ptr = REAL(_R), R->nrow = Rf_nrows(_R), R->ncol = Rf_ncols(_R);

    uul__Integer result = uul__dist (R, X, opt);

    free (R);
    free (X);
    
    if (result == UUL_ERROR)
        Rprintf ("dist failed!\n");

    return _R;
}

/* --------------------------------------------------------------------------*/
/**
 * @Synopsis  关系矩阵的合成
 *
 * @Param  _R1 输入的关系矩阵R1
 * @Param  _R2 输入的关系矩阵R2
 *
 * @Returns  合成的关系矩阵
 */
/* --------------------------------------------------------------------------*/
SEXP Ruul__bind (SEXP _R1, SEXP _R2)
{
    SEXP _Rt = Rf_allocMatrix (REALSXP, Rf_nrows(_R1), Rf_nrows(_R2));

    uul__MatrixP R1, R2, Rt;

    R1 = (uul__MatrixP) malloc (sizeof (uul__Matrix));
    R2 = (uul__MatrixP) malloc (sizeof (uul__Matrix));
    Rt = (uul__MatrixP) malloc (sizeof (uul__Matrix));

    R1->ptr = REAL(_R1), R1->nrow = Rf_nrows(_R1), R1->ncol = Rf_ncols(_R1);
    R2->ptr = REAL(_R2), R2->nrow = Rf_nrows(_R2), R2->ncol = Rf_ncols(_R2);
    Rt->ptr = REAL(_Rt), Rt->nrow = Rf_nrows(_Rt), Rt->ncol = Rf_ncols(_Rt);

    uul__Integer result = uul__bind (Rt, R1, R2);

    free (Rt);
    free (R1);
    free (R2);

    if (result == UUL_OK)
        Rprintf ("bind failed!\n");

    return _Rt;
}

