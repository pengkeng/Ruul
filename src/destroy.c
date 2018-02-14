/**
 * @file destroy.c
 * @Synopsis  矩阵的销毁
 * @author Tokhta Horqin
 * @version 0.2.1
 * @date 2018-02-14
 */

#include <stdlib.h>
#include "uul.h"

/* --------------------------------------------------------------------------*/
/**
 * @Synopsis  矩阵的销毁
 *
 * @Param X 矩阵
 *
 * @Returns   UUL_OK-矩阵销毁成功，UUL_ERROR-矩阵销毁失败
 **/
/* ----------------------------------------------------------------------------*/
uul__Status uul__destroy (uul__MatrixP X)
{
    free (X->ptr);

    return UUL_OK;
}

