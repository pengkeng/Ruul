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
uul__Status uul__destroy (uul__MatrixP X)
{
    for (uul__Integer i = 0; i < X->nrow; i++) {
        free (*(X->ptr + i));
    }
    free (X->ptr);

    return EXIT_SUCCESS;
}
