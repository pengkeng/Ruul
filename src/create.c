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
Status Create (MatrixP M, Integer nrow, Integer ncol)
{
    if (nrow <= 0 || ncol <= 0) {
        return _FAILTURE_;
    }

    M->nrow = nrow;
    M->ncol = ncol;

    M->ptr = (ElemTypePP) malloc (sizeof (ElemTypeP) * M->nrow);
    if (M->ptr == NULL) {
        return _OVERFLOW_;
    }

    for (Integer i = 0; i < M->nrow; i++) {
        *(M->ptr + i) = (ElemTypeP) malloc (sizeof (ElemType) * M->ncol);
        if (*(M->ptr + i) == NULL) {
            return _OVERFLOW_;
        }
    }

    return _SUCCESS_;
}


