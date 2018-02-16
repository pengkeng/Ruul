/**
 * @file bind.c
 * @Synopsis  关系矩阵的合成
 * @author Tokhta Horqin
 * @version 0.2.1
 * @date 2018-02-14
 */

/*
 *
 * 设
 * $X = {x_{1}, x_{2}, \cdots, x_{m}}$, 
 * $Y = {y_{1}, y_{2}, \cdots, y_{n}}$, 
 * $Z = {z_{1}, z_{2}, \cdots, z_{s}}$, 
 *
 * $X$到$Y$的关系矩阵$\mathbf{R}_{1}$的关系矩阵为
 * $\mathbf{R}_{1} = (r_{ij})_{m \times n}$, 
 * $Y$到$Z$的关系矩阵$\mathbf{R}_{1}$的关系矩阵为
 * $\mathbf{R}_{2} = (p_{ij})_{n \times s}$, 
 * 则$X$到$Z$的关系矩阵
 * $\mathbf{R}_{1} \circ \mathbf{R}_{2} = (c_{ij})_{m \times s}$, 
 * 其中
 * $c_{i, j} = \vee_{k = 1}^{n} (r_{ik} \wedge p_{kj}), i = 1, 2, \cdots, m; j = 1, 2, \cdots, s$.
 *
 */

#include <stdlib.h>
#include "uul.h"

/* --------------------------------------------------------------------------*/
/**
 * @Synopsis  关系矩阵的合成
 *
 * @Param Rt 合成的关系矩阵
 * @Param R1 输入的关系矩阵R1
 * @Param R2 输入的关系矩阵R2
 *
 * @Returns   UUL_OK-矩阵合成成功，UUL_ERROR-矩阵合成失败
 */
/* ----------------------------------------------------------------------------*/
uul__Status uul__bind (uul__MatrixP Rt, uul__MatrixP R1, uul__MatrixP R2)
{
    if (R1->nrow <= 0 || R1->ncol <= 0) 
        return UUL_ERROR;
    if (R2->nrow <= 0 || R2->ncol <= 0) 
        return UUL_ERROR;
    if (Rt->nrow <= 0 || Rt->ncol <= 0) 
        return UUL_ERROR;
    if (R1->nrow != R1->ncol || R2->nrow != R2->ncol || Rt->nrow != Rt->ncol) 
        return UUL_ERROR;
    if (Rt->nrow != R1->nrow || Rt->nrow != R2->nrow) 
        return UUL_ERROR;

    uul__ElemType temp;

    for (uul__Integer i = 0; i < R1->nrow; i++) {
        for (uul__Integer j = 0; j < R2->ncol; j++) {
            Rt->ptr[i + j * R1->nrow] = 0;
            for (uul__Integer k = 0; k < R1->ncol; k++) {
                temp = R2->ptr[k + j * R2->nrow];
                if (R1->ptr[i + k * R1->nrow] < temp) {
                    temp = R1->ptr[i + k * R1->nrow];
                }
                if (Rt->ptr[i + j * Rt->nrow] < temp) {
                    Rt->ptr[i + j * Rt->nrow] = temp;
                }
            }
        }
    }
    return UUL_OK;
}

