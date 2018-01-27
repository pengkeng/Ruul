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
Status Destroy (MatrixP M)
{
    for (Integer i = 0; i < M->nrow; i++) {
        free (*(M->ptr + i));
    }
    free (M->ptr);

    return _SUCCESS_;
}
