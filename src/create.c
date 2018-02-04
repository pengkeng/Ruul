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
U_Status U_create (U_MatrixP M, U_Integer nrow, U_Integer ncol)
{
    if (nrow <= 0 || ncol <= 0) {
        return U_FAILTURE;
    }

    M->nrow = nrow;
    M->ncol = ncol;

    M->ptr = (U_ElemTypePP) malloc (sizeof (U_ElemTypeP) * M->nrow);
    if (M->ptr == NULL) {
        return U_OVERFLOW;
    }

    for (U_Integer i = 0; i < M->nrow; i++) {
        *(M->ptr + i) = (U_ElemTypeP) malloc (sizeof (U_ElemType) * M->ncol);
        if (*(M->ptr + i) == NULL) {
            return U_OVERFLOW;
        }
    }

    return U_SUCCESS;
}


