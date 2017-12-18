#include <stdlib.h>
#include <math.h>
#include "uul.h"

/* --------------------------------------------------------------------------*/
/**
 * @Synopsis  矩阵的创建
 *
 * @Param M 矩阵
 * @Param nrow 矩阵的行数
 * @Param ncol 矩阵的列数
 *
 * @Returns   0—矩阵创建成功，1—矩阵创建失败，-2—内存不足
 */
/* ----------------------------------------------------------------------------*/
_Status matrixCreate (_Matrix &M, _Integer nrow, _Integer ncol)
{
    if (nrow <= 0 || ncol <= 0) {
        return _FAILTURE_;
    }

    M.nrow = nrow;
    M.ncol = ncol;

    M.ptr = (_ElemType **) malloc (sizeof (_ElemType *) * M.nrow);
    if (M.ptr == NULL) {
        return _OVERFLOW_;
    }

    for (_Integer i = 0; i < M.nrow; i++) {
        *(M.ptr + i) = (_ElemType *)calloc(M.ncol, sizeof (_ElemType));
        if (*(M.ptr + i) == NULL) {
            return _OVERFLOW_;
        }
    }

    return _SUCCESS_;
}

/* --------------------------------------------------------------------------*/
/**
 * @Synopsis  矩阵的销毁
 *
 * @Param M 矩阵
 *
 * @Returns   0-矩阵销毁成功，1-矩阵销毁失败
 */
/* ----------------------------------------------------------------------------*/
_Status matrixDestroy (_Matrix &M)
{
    for (_Integer i = 0; i < M.nrow; i++) {
        free (*(M.ptr + i));
        if (*(M.ptr + i) == NULL) {
            return _FAILTURE_;
        }
    }
    free (M.ptr);
    if (M.ptr == NULL) {
        return _FAILTURE_;
    }

    return _SUCCESS_;
}

