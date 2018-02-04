/*
 *
 * 设论域$U = {x_{1}, x_{2}, \cdots, x_{n}}$为被分类的对象，
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

#include "uul.h"

/* --------------------------------------------------------------------------*/
/**
 * @Synopsis  标准矩阵的创建
 *
 * @Param Xstd 创建的标准矩阵
 * @Param X 输入的数据矩阵
 * @Param opt 标准矩阵创建的方法
 *
 * @Returns   0-矩阵标准化成功，1—矩阵标准化失败，-1—输入数据矩阵存在严重问题
 */
/* ----------------------------------------------------------------------------*/
U_Status U_scale (U_MatrixP Xstd, U_MatrixP X, U_Integer opt)
{
    if (X->nrow == 0 || X->ncol == 0) {
        return U_FAILTURE;
    }
    if (Xstd->nrow == 0 || Xstd->ncol == 0) {
        return U_FAILTURE;
    }
    if (Xstd->nrow != X->nrow || Xstd->ncol != X->ncol) {
        return U_FAILTURE;
    }

	if (opt == 0) {
        for (U_Integer j = 0; j < X->ncol; j++) {
            for (U_Integer i = 0; i < X->nrow; i++) {
                *(*(Xstd->ptr + i) + j) = *(*(X->ptr + i) + j); 
            }
        }
	}
    else if (opt == 1) {
		U_ElemType sk, xk;

		for (U_Integer j = 0; j < X->ncol; j++) {
			xk = 0;
			for (U_Integer i = 0; i < X->nrow; i++) {
				xk += *(*(X->ptr + i) + j);
			}
			xk /= X->nrow;
			sk = 0;
			for (U_Integer i = 0; i < X->nrow; i++) {
				sk += pow (*(*(X->ptr + i) + j) - xk, 2);
			}
			sk = sqrt (sk / X->nrow);
			if (sk > 1E-6) {
				for (U_Integer i = 0; i < X->nrow; i++) {
					*(*(Xstd->ptr + i) + j) = (*(*(X->ptr + i) + j) - xk) / sk;
				}
			}
		}
	} 
    else if (opt == 2) {
		U_ElemType xmin, xmax;

		for (U_Integer j = 0; j < X->ncol; j++) {
			xmin = *(*(X->ptr + j)); xmax = *(*(X->ptr + j));
			for (U_Integer i = 0; i < X->nrow; i++) {
				if (xmin > *(*(X->ptr + i) + j)) {
					xmin = *(*(X->ptr + i) + j);
				}
				if (xmax < *(*(X->ptr + i) + j)) {
					xmax = *(*(X->ptr + i) + j);
				}
			}
			if (xmax > xmin) {
				xmax = xmax - xmin;
				for (U_Integer i = 0; i < X->nrow; i++) {
					*(*(Xstd->ptr + i) + j) = (*(*(X->ptr + i) + j) - xmin) / xmax;
				}
			} 
            else {
				for (U_Integer i = 0; i < X->nrow; i++) {
					*(*(Xstd->ptr + i) + j) = 0;
				}
			}
		}
	} 
    else if (opt == 3) {
        for (U_Integer j = 0; j < X->ncol; j++) {
            for (U_Integer i = 0; i < X->nrow; i++) {
                *(*(Xstd->ptr + i) + j + 0) = log10 (*(*(Xstd->ptr + i) + j));
            }
        }
    } 
    else {
        return U_FAILTURE;
    }

    return U_SUCCESS;
}

