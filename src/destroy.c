#include "uul.h"

/* --------------------------------------------------------------------------*/
/**
 * @Synopsis  矩阵的销毁
 *
 * @Param X 矩阵
 *
 * @Returns   0-矩阵销毁成功，1-矩阵销毁失败
 **/
/* ----------------------------------------------------------------------------*/
U_Status U_destroy (U_MatrixP X)
{
    for (U_Integer i = 0; i < X->nrow; i++) {
        free (*(X->ptr + i));
    }
    free (X->ptr);

    return U_SUCCESS;
}
