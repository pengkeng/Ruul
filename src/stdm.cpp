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

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "uul.h"

_Status matrixStandard (_Matrix &Xstd, _Matrix X, _Integer opt)
{
    if (X.nrow == 0 || X.ncol == 0) {
        return _ERROR_;
    }
    if (Xstd.nrow == 0 || Xstd.ncol == 0) {
        return _ERROR_;
    }
    if (Xstd.nrow != X.nrow || Xstd.ncol != X.ncol) {
        return _ERROR_;
    }

	if (opt == 0) {
        for (_Integer j = 0; j < X.ncol; j++) {
            for (_Integer i = 0; i < X.nrow; i++) {
                *(*(Xstd.ptr + i) + j) = *(*(X.ptr + i) + j); 
            }
        }
	}
    else if (opt == 1) {
		_ElemType sk, xk;

		for (_Integer j = 0; j < X.ncol; j++) {
			xk = 0;
			for (_Integer i = 0; i < X.nrow; i++) {
				xk += *(*(X.ptr + i) + j);
			}
			xk /= X.nrow;
			sk = 0;
			for (_Integer i = 0; i < X.nrow; i++) {
				sk += pow (*(*(X.ptr + i) + j) - xk, 2);
			}
			sk = sqrt (sk / X.nrow);
			if (sk > 1E-6) {
				for (_Integer i = 0; i < X.nrow; i++) {
					*(*(Xstd.ptr + i) + j) = (*(*(X.ptr + i) + j) - xk) / sk;
				}
			}
		}
	} 
    else if (opt == 2) {
		_ElemType xmin, xmax;

		for (_Integer j = 0; j < X.ncol; j++) {
			xmin = *(*(X.ptr + j)); xmax = *(*(X.ptr + j));
			for (_Integer i = 0; i < X.nrow; i++) {
				if (xmin > *(*(X.ptr + i) + j)) {
					xmin = *(*(X.ptr + i) + j);
				}
				if (xmax < *(*(X.ptr + i) + j)) {
					xmax = *(*(X.ptr + i) + j);
				}
			}
			if (xmax > xmin) {
				xmax = xmax - xmin;
				for (_Integer i = 0; i < X.nrow; i++) {
					*(*(Xstd.ptr + i) + j) = (*(*(X.ptr + i) + j) - xmin) / xmax;
				}
			} 
            else {
				for (_Integer i = 0; i < X.nrow; i++) {
					*(*(Xstd.ptr + i) + j) = 0;
				}
			}
		}
	} 
    else if (opt == 3) {
        for (_Integer j = 0; j < X.ncol; j++) {
            for (_Integer i = 0; i < X.nrow; i++) {
                *(*(Xstd.ptr + i) + j + 0) = log10 (*(*(Xstd.ptr + i) + j));
            }
        }
    } 
    else {
        return _ERROR_;
    }

    return _SUCCESS_;
}

