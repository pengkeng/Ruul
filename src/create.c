#include "uul.h"

/* --------------------------------------------------------------------------*/
/**
 * @Synopsis  矩阵的创建
 *
 * @Param X 矩阵
 * @Param nrow 矩阵的行数
 * @Param ncol 矩阵的列数
 *
 * @Returns   0—矩阵创建成功，1—矩阵创建失败，3—内存不足
 */
/* ----------------------------------------------------------------------------*/
uul__Status uul__create (uul__MatrixP X, uul__Integer nrow, uul__Integer ncol)
{
    if (nrow <= 0 || ncol <= 0) {
        return EXIT_FAILURE;
    }

    X->nrow = nrow;
    X->ncol = ncol;

    X->ptr = (uul__ElemType *) malloc (sizeof (uul__ElemType) * X->nrow * X->ncol);
    if (X->ptr == NULL) {
        return OVERFLOW;
    }

    return EXIT_SUCCESS;
}

