/**
 * @file create.c
 * @Synopsis  矩阵的创建
 * @author Tokhta Horqin
 * @version 0.2.1
 * @date 2018-02-14
 */

#include <stdlib.h>
#include "uul.h"

/* --------------------------------------------------------------------------*/
/**
 * @Synopsis  矩阵的创建
 *
 * @Param X 矩阵
 * @Param nrow 矩阵的行数
 * @Param ncol 矩阵的列数
 *
 * @Returns   UUL_OK—矩阵创建成功，UUL_ERROR—矩阵创建失败
 */
/* ----------------------------------------------------------------------------*/
uul__Status uul__create (uul__MatrixP X, uul__Integer nrow, uul__Integer ncol)
{
    if (nrow <= 0 || ncol <= 0) {
        return UUL_ERROR;
    }

    X->nrow = nrow;
    X->ncol = ncol;

    X->ptr = (uul__ElemType *) malloc (sizeof (uul__ElemType) * X->nrow * X->ncol);
    if (X->ptr == NULL) {
        return UUL_ERROR;
    }

    return UUL_OK;
}

