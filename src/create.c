#include "uul.h"

/* --------------------------------------------------------------------------*/
/**
 * @Synopsis  矩阵的创建
 *
 * @Param X 矩阵
 * @Param nrow 矩阵的行数
 * @Param ncol 矩阵的列数
 *
 * @Returns   0—矩阵创建成功，1—矩阵创建失败，-2—内存不足
 */
/* ----------------------------------------------------------------------------*/
U_Status U_create (U_MatrixP X, U_Integer nrow, U_Integer ncol)
{
    if (nrow <= 0 || ncol <= 0) {
        return U_FAILTURE;
    }

    X->nrow = nrow;
    X->ncol = ncol;

    X->ptr = (U_ElemTypePP) malloc (sizeof (U_ElemTypeP) * X->nrow);
    if (X->ptr == NULL) {
        return U_OVERFLOW;
    }

    for (U_Integer i = 0; i < X->nrow; i++) {
        *(X->ptr + i) = (U_ElemTypeP) malloc (sizeof (U_ElemType) * X->ncol);
        if (*(X->ptr + i) == NULL) {
            return U_OVERFLOW;
        }
    }

    return U_SUCCESS;
}


