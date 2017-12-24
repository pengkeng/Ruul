/*
 *
 * 设
 * $X = {x_{1}, x_{2}, \cdots, x_{m}}$, 
 * $Y = {y_{1}, y_{2}, \cdots, y_{n}}$, 
 * $Z = {z_{1}, z_{2}, \cdots, z_{s}}$, 
 *
 * $X$到$Y$的关系矩阵$\mathbf{R}_{1}$的关系矩阵为
 *  $\mathbf{R}_{1} = (r_{ij})_{m \times n}$, 
 * $Y$到$Z$的关系矩阵$\mathbf{R}_{1}$的关系矩阵为
 * $\mathbf{R}_{2} = (p_{ij})_{n \times s}$, 
 * 则$X$到$Z$的关系矩阵
 * $\mathbf{R}_{1} \circ \mathbf{R}_{2} = (c_{ij})_{m \times s}$, 
 * 其中
 * $c_{i, j} = \vee_{k = 1}^{n} (r_{ik} \wedge p_{kj}), i = 1, 2, \cdots, m; j = 1, 2, \cdots, s$.
 *
 */

#include <stdlib.h>
#include <math.h>
#include "uul.h"

    /* --------------------------------------------------------------------------*/
    /**
     * @Synopsis  关系矩阵的合成
     *
     * @Param R 合成的关系矩阵
     * @Param R1 输入的关系矩阵R1
     * @Param R2 输入的关系矩阵R2
     *
     * @Returns   0-矩阵合成成功，1-矩阵合成失败
     */
    /* ----------------------------------------------------------------------------*/
_Status matrixComposite (_PMatrix Rt, _PMatrix R1, _PMatrix R2)
{
    if (R1->nrow <= 0 || R1->ncol <= 0) {
        return _FAILTURE_;
    }
    if (R2->nrow <= 0 || R2->ncol <= 0) {
        return _FAILTURE_;
    }
    if (Rt->nrow <= 0 || Rt->ncol <= 0) {
        return _FAILTURE_;
    }
    if (R1->nrow != R1->ncol || R2->nrow != R2->ncol || Rt->nrow != Rt->ncol) {
        return _FAILTURE_;
    }
    if (Rt->nrow != R1->nrow || Rt->nrow != R2->nrow) {
        return _FAILTURE_;
    }

    _ElemType temp;

    for (_Integer i = 0; i < R1->nrow; i++) {
        for (_Integer j = 0; j < R2->ncol; j++) {
            *(*(Rt->ptr + i)+ j) = 0;
            for (_Integer k = 0; k < R1->ncol; k++) {
                temp = *(*(R2->ptr + k)+ j);
                if (*(*(R1->ptr + i) + k) < temp) {
                    temp = *(*(R1->ptr + i) + k);
                }
                if (*(*(Rt->ptr + i)+ j) < temp) {
                    *(*(Rt->ptr + i)+ j) = temp;
                }
            }
        }
    }
    return _SUCCESS_;
}
