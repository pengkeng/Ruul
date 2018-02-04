#include "uul.h"

/* --------------------------------------------------------------------------*/
/**
 * @Synopsis  矩阵的销毁
 *
 * @Param M 矩阵
 *
 * @Returns   0-矩阵销毁成功，1-矩阵销毁失败
 **/
/* ----------------------------------------------------------------------------*/
U_Status U_destroy (U_MatrixP M)
{
    for (U_Integer i = 0; i < M->nrow; i++) {
        free (*(M->ptr + i));
    }
    free (M->ptr);

    return U_SUCCESS;
}
