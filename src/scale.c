/*
 *
 * 设论域$uul_ = {x_{1}, x_{2}, \cdots, x_{n}}$为被分类的对象，
 * 每个对象又由m的指标表示其性状，即
 *
 * \begin{center}
 * $x_{i} = (x_{i1}, x_{i2}, \cdots, x_{im}), i = 1, 2, \cdots, m$
 * \end{center}
 *
 * 通常采用作如下几种变换：
 *
 * \section{平移·标准差变换}
 *
 * \begin{center}
 * $x'_{ik} = \frac{x_{ik} - \bar{x_{k}}}{s_{k}} (i = 1, 2, \cdots, n; k = 1, 2, \cdots, m)$,
 * \end{center}
 *
 * 其中
 * \begin{center}
 * $\bar{x_{k}} = \frac{1}{n} \sum \limits_{i = 1}^{n}{x_{ik}}$, 
 * \end{center}
 *
 * \section{平移·极差变换}
 *
 * \begin{center}
 * $x'' = \frac{x'_{ik} - \min\limits_{i \leqslant i \leqslant n}{x'_{ik}}}{\max \limits_{1 \leqslant i \leqslant n}{x'_{ik}} - \min \limits_{1 \leqslant i \leqslant n}{x'_{ik}}} (k = 1, 2, \cdots, m)$,
 * \end{center}
 *
 * \section{对数变换}
 *
 * \begin{center}
 * $x'_{ik} = \lg{x_{ik}} (i = 1, 2, \cdots n; k = 1, 2, \cdots, m,$
 * \end{center}
 *
 */

#include <math.h>
#include "uul.h"

/* --------------------------------------------------------------------------*/
/**
 * @Synopsis  标准矩阵的创建
 *
 * @Param Xstd 创建的标准矩阵
 * @Param X 输入的数据矩阵
 * @Param opt 标准矩阵创建的方法
 *
 * @Returns   UUL_OK-矩阵标准化成功，UUL_ERROR—矩阵标准化失败
 */
/* ----------------------------------------------------------------------------*/
uul__Status uul__scale (uul__MatrixP Xstd, uul__MatrixP X, uul__Integer opt)
{
    if (X->nrow == 0 || X->ncol == 0) {
        return UUL_ERROR;
    }
    if (Xstd->nrow == 0 || Xstd->ncol == 0) {
        return UUL_ERROR;
    }
    if (Xstd->nrow != X->nrow || Xstd->ncol != X->ncol) {
        return UUL_ERROR;
    }

	if (opt == 0) {
        for (uul__Integer j = 0; j < X->ncol; j++) {
            for (uul__Integer i = 0; i < X->nrow; i++) {
                Xstd->ptr[i + j * Xstd->nrow] = X->ptr[i + j * X->nrow]; 
            }
        }
	}
    else if (opt == 1) {
		uul__ElemType sk, xk;

		for (uul__Integer j = 0; j < X->ncol; j++) {
			xk = 0;
			for (uul__Integer i = 0; i < X->nrow; i++) {
				xk += X->ptr[i + j * X->nrow];
			}
			xk /= X->nrow;
			sk = 0;
			for (uul__Integer i = 0; i < X->nrow; i++) {
				sk += pow (X->ptr[i + j * X->nrow] - xk, 2);
			}
			sk = sqrt (sk / X->nrow);
			if (sk > 1E-6) {
				for (uul__Integer i = 0; i < X->nrow; i++) {
					Xstd->ptr[i + j * Xstd->nrow] = (X->ptr[i + j * X->nrow] - xk) / sk;
				}
			}
		}
	} 
    else if (opt == 2) {
		uul__ElemType xmin, xmax;

		for (uul__Integer j = 0; j < X->ncol; j++) {
			xmin = X->ptr[j + 0 * X->nrow]; xmax = X->ptr[j + 0 * X->nrow];
			for (uul__Integer i = 0; i < X->nrow; i++) {
				if (xmin > X->ptr[i + j * X->nrow]) {
					xmin = X->ptr[i + j * X->nrow];
				}
				if (xmax < X->ptr[i + j * X->nrow]) {
					xmax = X->ptr[i + j * X->nrow];
				}
			}
			if (xmax > xmin) {
				xmax = xmax - xmin;
				for (uul__Integer i = 0; i < X->nrow; i++) {
					Xstd->ptr[i + j * Xstd->nrow] = (X->ptr[i + j * X->nrow] - xmin) / xmax;
				}
			} 
            else {
				for (uul__Integer i = 0; i < X->nrow; i++) {
					Xstd->ptr[i + j * Xstd->nrow] = 0;
				}
			}
		}
	} 
    else if (opt == 3) {
        for (uul__Integer j = 0; j < X->ncol; j++) {
            for (uul__Integer i = 0; i < X->nrow; i++) {
                Xstd->ptr[i + j * Xstd->nrow] = log10 (Xstd->ptr[i + j * Xstd->nrow]);
            }
        }
    } 
    else {
        return UUL_ERROR;
    }

    return UUL_OK;
}

