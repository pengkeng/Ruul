/**
 * @file dist.c
 * @Synopsis  相似矩阵的创建
 * @author Tokhta Horqin
 * @version 0.2.1
 * @date 2018-02-14
 */

/*
 *
 * 设论域
 * $\mathbf{uul_} = {{x}_{1}, x_{2}, \cdots, x_{n}}$, 
 * $x_{i} = {x_{xi1}, x_{i2}, \cdots, x_{im}}$, 
 * 而$x_{i}$和$x_{j}$的模糊相似系数$r_{ij} = \mathbf{R}(x_{i}, x_{j})$. 
 *
 * \section{相似系数法}
 *
 * \subsection{数量积法}
 *
 * $$
 * r_{ij} =
 * \begin{cases}
 * 1,& i = j,\\
 * \frac{1}{M} \sum\limits_{k = 1}^{m} x_{ik} x_{jk},& i \neq j,
 * \end{cases}
 * $$
 *
 * 其中
 * \begin{center} 
 * $M = \max\limits_{i \neq j}(\sum\limits_{k = 1}^{m} x_{ik} x_{ik})$.
 * \end{center}
 *
 * 令$r'_{ij} = \frac{r_{ij} + 1}{2}$, 
 * 则$r'_{ij} \in [0, 1]$, 将$r_{ij}$压缩到$[0, 1]$. 
 *
 * \subsection{夹角余弦法}
 *
 * \begin{center}
 * $r_{ij} = \frac{\sum\limits_{k = 1}^{m} x_{ik} x_{jk}}{\sqrt{\sum\limits_{k = 1}^{m} x_{ik}^{2}} \sqrt{\sum\limits_{k = 1}^{m} x_{jk}^{2}}}$ 
 * \end{center}
 *
 * \subsection{相关系数法}
 *
 * \begin{center}
 * $r_{ij} = \frac{\sum\limits_{k = 1}^{m} \lvert x_{ik} - \bar{x_{i}} \rvert \lvert x_{jk} - \bar{x_{j}} \rvert}{\sqrt{\sum\limits_{k = 1}^{m}(x_{ik} - \bar{x_{i}})^{2} \sqrt{\sum\limits_{k = 1}^{m}(x_{jk} - \bar{x_{j}})^{2}}}}$
 * \end{center}
 *
 * 其中 
 *
 * \begin{center}
 * $\bar{x_{i}} = \frac{1}{m} \sum\limits_{k = 1}^{m} x_{ik}, \bar{x_{j}} = \frac{1}{m} \sum\limits_{k = 1}^{m} x_{jk}.$
 * \end{center}
 *
 * \subsection{指数相关系数法}
 *
 * \begin{center}
 * $r_{ij} = \frac{1}{M} \sum\limits_{k = 1}^{m} exp[-\frac{3}{4} \frac{(x_{ik} - x_{jk})^{2}}{s_{k}^{2}}]$, 
 * \end{center}
 *
 * 其中
 * \begin{center} 
 * $s_{k}^{2} = \frac{1}{n} \sum\limits_{i = 1}^{n} (x_{ik} - \bar{x_{ik}})^{2}$, 
 * \end{center}
 *
 * 而
 * \begin{center} 
 * $\bar{x_{k}} = \frac{1}{n} \sum\limits_{i = 1}^{n} x_{ik} (k = 1, 2, \cdots, m)$. 
 * \end{center}
 *
 * \subsection{最大最小法}
 *
 * \begin{center}
 * $r_{ij} = \frac{\sum\limits_{k = 1}^{m} (x_{ik} \wedge x_{jk})}{\sum\limits_{k = 1}^{m} (x_{ik} \vee x_{jk})}$
 * \end{center}
 *
 * \subsection{算术平均最小法}
 *
 * \begin{center}
 * $r_{ij} = \frac{2 \sum\limits_{k = 1}^{m}(x_{ik} \wedge x_{jk})}{\sum\limits_{k = 1}^{m} (x_{ik} + x_{jk})}$
 * \end{center}
 *
 * \subsection{几何平均最小法}
 *
 * \begin{center}
 * $r_{ij} = \frac{\sum\limits_{k = 1}^{m} (x_{ik} \wedge x_{jk})}{\sum\limits_{k = 1}^{m} \sqrt{x_{ik} x_{jk}}}$
 * \end{center}
 *
 * \section{距离法}
 *
 * \subsection{直接距离法}
 *
 * \begin{center}
 * $r_{ij} = 1 - cd(x_{i}, x_{j})$.
 * \end{center}
 *
 * 其中$c$为适当选取的参数, 
 * 使$0 \le r_{ij} \le 1$, $d(x_{i}, x_{j})$表示$x_{i}$与$x_{j}$的距离. 
 * 经典的距离有以下三种：
 *
 * \subsection{海明距离}
 *
 * \begin{center}
 * $d(x_{i}, x_{j}) = \sum\limits_{k = 1}^{m} \lvert x_{ik} - x_{jk} \rvert$;
 * \end{center}
 *
 * \subsection{欧几里得距离}
 *
 * \begin{center}
 * $d(x_{i}, x_{j}) = \sqrt{\sum\limits_{k = 1}^{m}(x_{ik} - x_{jk})^{2}}$;
 * \end{center}
 *
 * \subsection{切比雪夫距离}
 *
 * \begin{center}
 * $d(x_{i}, x_{j}) = \vee_{k = 1}^{m} \lvert x_{ik} - x_{jk} \rvert$.
 * \end{center}
 *
 * \section{倒数距离法}
 *
 * $$
 * r_{ij} =
 * \begin{cases}
 * 1,& i = j, \\
 * \frac{M}{d(x_{i}, x_{j})},& i \neq j,
 * \end{cases}
 * $$
 *
 * 其中M为适当选取的参数，使得$0 \le r_{ij} \le 1$.
 *
 */

#include <math.h>
#include "uul.h"

/* --------------------------------------------------------------------------*/
/**
 * @Synopsis  相似矩阵的创建
 *
 * @Param R 创建的相似矩阵
 * @Param X 输入的数据矩阵
 * @Param opt 相似矩阵创建的方法
 *
 * @Returns   UUL_OK—矩阵闭包创建成功，UUL_ERROR—矩阵闭包创建失败
 */
/* ----------------------------------------------------------------------------*/
uul__Status uul__dist (uul__MatrixP R, uul__MatrixP X, uul__Integer opt)
{
    if (X->nrow <= 0 || X->ncol <= 0) 
        return UUL_ERROR;
    if (R->nrow <= 0 || R->ncol <= 0) 
        return UUL_ERROR;
    if (R->nrow != X->nrow || R->ncol != X->nrow) 
        return UUL_ERROR;

    if (opt < 1 || opt > 16)
        return UUL_ERROR;

    uul__Integer i, j, k, z;
    uul__ElemType c, d, e, s, t;
    uul__ElemType xi, xj, xk, sk, fz, fm;
    uul__ElemType xis, xjs;
    uul__ElemType minM, maxM;

    if (opt == 1) {
        maxM = 0;
        for (i = 0; i < X->nrow; i++) {
            for (j = 0; j < X->nrow; j++) {
                if (i != j) {
                    t = 0;
                    for (k = 0; k < X->ncol; k++) {
                        t += X->ptr[i + k * X->nrow] * X->ptr[j + k * X->nrow];
                    }
                    if (maxM < t) {
                        maxM = t;
                    } 
                    else if (maxM < -t) {
                        maxM = -t;
                    }
                }
            }
        }
        maxM += 1;
        for (i = 0; i < X->nrow; i++) {
            for (j = 0; j < X->nrow; j++) {
                if (i == j) {
                    R->ptr[i + j * R->nrow] = 1;
                } 
                else {
                    R->ptr[i + j * R->nrow] = 0;
                    for (k = 0; k < X->ncol; k++) {
                        R->ptr[i + j * R->nrow] += X->ptr[i + k * X->nrow] * X->ptr[j + k * X->nrow];
                    }
                    R->ptr[i + j * R->nrow] /= maxM;
                    if (R->ptr[i + j * R->nrow] < 0) {
                        R->ptr[i + j * R->nrow] = (R->ptr[i + j * R->nrow] + 1) / 2;
                    }
                }
            }
        } 
    } 
    else if (opt == 2) {
        for (i = 0; i < X->nrow; i++) {
            for (j = 0; j < X->nrow; j++) {
                xi = 0; xj = 0;
                for (k = 0; k < X->ncol; k++) {
                    xi += X->ptr[i + k * X->nrow] * X->ptr[i + k * X->nrow];
                    xj += X->ptr[j + k * X->nrow] * X->ptr[j + k * X->ncol];
                }
                s = sqrt (xi * xj);
                R->ptr[i + j * R->nrow] = 0;
                for (k = 0; k < X->ncol; k++) {
                    R->ptr[i + j * R->nrow] += 
                        X->ptr[i + k * X->nrow] * X->ptr[j + k * X->nrow];
                }
                R->ptr[i + j * R->nrow] /= s;
                if (R->ptr[i + j * R->nrow] <  0) {
                    R->ptr[i * R->nrow + j] = (R->ptr[i + j * R->nrow] + 1) / 2;
                }
            }
        }
    }
    else if (opt == 3) {
        for (i = 0; i < X->nrow; i++) {
            for (j = 0; j < X->nrow; j++) {
                xi = 0; xj = 0;
                for (k = 0; k < X->ncol; k++) {
                    xi += X->ptr[i + k * X->nrow];
                    xj += X->ptr[j + k * X->nrow];
                }
                xi /= X->ncol; 
                xj /= X->ncol;
                xis = 0; xjs = 0;
                for (k = 0; k < X->ncol; k++) {
                    xis += pow (X->ptr[i + k * X->nrow] - xi, 2);
                    xjs += pow (X->ptr[j + k * X->nrow] - xj, 2);
                }
                s = sqrt (xis * xjs);
                R->ptr[i + j * R->nrow] = 0;
                for (k = 0; k < X->ncol; k++) {
                    R->ptr[i + j * R->nrow] += 
                        fabs ((X->ptr[i + k * X->nrow] - xi) * (X->ptr[j + k * X->nrow] - xj));
                }
                R->ptr[i + j * R->nrow] /= s;
            }
        }
    } 
    else if (opt == 4) {
        for (i = 0; i < X->nrow; i++) {
            for (j = 0; j < X->nrow; j++) {
                R->ptr[i + j * R->nrow] = 0;
                for (k = 0; k < X->ncol; k++) {
                    xk= 0;
                    for (z = 0; z < X->nrow; z++) {
                        xk += X->ptr[z + k * X->nrow];
                    }
                    xk /= X->nrow;
                    sk = 0;
                    for (z = 0; z < X->nrow; z++) {
                        sk += pow(X->ptr[z + k * X->nrow] - xk, 2);
                    }                    
                    sk /= X->nrow;
                    e = 
                        -0.75 * pow (X->ptr[i + k * X->nrow] - X->ptr[j + k * X->nrow], 2) / sk;
                    R->ptr[i + j * R->nrow] += exp (e);
                }
                R->ptr[i + j * R->nrow] /= X->ncol;
            }
        }
    } 
    else if (opt <= 7) {
        for (i = 0; i < X->nrow; i++) {
            for (j = 0; j < X->nrow; j++) {
                fz = 0; 
                fm = 0;
                for (k = 0; k < X->ncol; k++) {
                    if (X->ptr[j + k * X->nrow] < 0) {
                        return UUL_ERROR;
                    }
                    if (X->ptr[j + k * X->nrow] < X->ptr[i + k * X->nrow]) {
                        fz += X->ptr[i + k * X->nrow];
                    } 
                    else {
                        fz += X->ptr[j + k * X->nrow];
                    }
                }
                if (opt == 5) {
                    for (k = 0; k < X->ncol; k++) {
                        if (X->ptr[i + k * X->nrow] > X->ptr[j + k * X->nrow]) {
                            fm += X->ptr[i + k * X->nrow];
                        } 
                        else {
                            fm += X->ptr[j + k * X->nrow];
                        } 
                    }
                } 
                else if (opt == 6) {
                    for (k = 0; k < X->ncol; k++) {
                        fm += (X->ptr[i + k * X->nrow] + X->ptr[j + k * X->nrow]) / 2;
                    }
                } 
                else if (opt == 7) {
                    for (k = 0; k < X->ncol; k++) {
                        fm += sqrt (X->ptr[i + k * X->nrow] * X->ptr[j + k * X->nrow]);
                    }
                }
                R->ptr[i + j * R->nrow] = fz / fm;
            }
        }
    } 
    else if (opt <= 10) {
        c = 0;
        for (i = 0; i < X->nrow; i++) {
            for (j = i + 1; j < X->nrow; j++) {
                d = 0;
                if (opt == 8) {
                    for (k = 0; k < X->ncol; k++) {
                        d += pow ((X->ptr[i + k * X->nrow] - X->ptr[j + k * X->nrow]), 2);
                    }
                    d = sqrt (d);
                } 
                else if (opt == 9) {
                    for (k = 0; k < X->ncol; k++) {
                        d += fabs (X->ptr[i + k * X->nrow] - X->ptr[j + k * X->nrow]);
                    }
                } 
                else if (opt == 10) {
                    for (k = 0; k < X->ncol; k++) {
                        if (d < fabs (X->ptr[i + k * X->nrow] - X->ptr[j + k * X->nrow])) {
                            d = fabs (X->ptr[i + k * X->nrow] - X->ptr[j + k * X->nrow]);
                        }
                    }
                }
                if (c < d) {
                    c = d;
                }
            }
        }
        c = 1.0 / (1.0 + c);
        for (i = 0; i < X->nrow; i++) {
            for (j = 0; j < X->nrow; j++) {
                d = 0;
                if (opt == 8) {
                    for (k = 0; k < X->ncol; k++) {
                        d += pow (X->ptr[i + k * X->nrow] -X->ptr[j + k * X->nrow] , 2);
                    }
                    d = sqrt (d);
                } 
                else if (opt == 9) {
                    for (k = 0; k < X->ncol; k++) {
                        d += fabs (X->ptr[i + k * X->nrow] - X->ptr[j + k * X->nrow]);
                    }
                } 
                else if (opt == 10) {
                    for (k = 0; k < X->ncol; k++) {
                        if (d < fabs (X->ptr[i + k * X->nrow] - X->ptr[j + k * X->nrow])) {
                            d = fabs (X->ptr[i + k * X->nrow] - X->ptr[j + k * X->nrow]);
                        }
                    }
                }
                R->ptr[i + j * R->nrow] = 1 - c * d;
            }
        }
    } 
    else if (opt <= 13) {
        minM = 1E+6;
        for (i = 0; i < X->nrow; i++) {
            for (j = i + 1; j < X->nrow; j++) {
                d = 0;
                if (opt == 11) {
                    for (k = 0; k < X->ncol; k++) {
                        d += pow (X->ptr[i + k * X->nrow] - X->ptr[j + k * X->nrow], 2);
                    }
                    d = sqrt (d);
                } 
                else if (opt == 12) {
                    for (k = 0; k < X->ncol; k++) {
                        d += fabs (X->ptr[i + k * X->nrow] - X->ptr[j + k * X->nrow]);
                    }
                } 
                else if (opt == 13) {
                    for (k = 0; k < X->ncol; k++) {
                        if (d < fabs (X->ptr[i + k * X->nrow] - X->ptr[j + k * X->nrow])) {
                            d = fabs (X->ptr[i + k * X->nrow] - X->ptr[j + k * X->nrow]);
                        }
                    }
                }
                if (minM > d) {
                    minM = d;
                }
            }
        }
        minM *= 0.9999;
        for (i = 0; i < X->nrow; i++) {
            for (j = 0; j < X->nrow; j++) {
                d = 0;
                if (i == j) {
                    R->ptr[i + j * R->nrow] = 1;
                    continue;
                }
                if (opt == 11) {
                    for (k = 0; k < X->ncol; k++) {
                        d += pow (X->ptr[i + k * X->nrow]- X->ptr[j + k * X->nrow], 2);
                    }
                    d = sqrt(d);
                } 
                else if (opt == 12) {
                    for (k = 0; k < X->ncol; k++) {
                        d += fabs (X->ptr[i + k * X->nrow] - X->ptr[j + k * X->nrow]);
                    }
                } 
                else if (opt == 13) {
                    for (k = 0; k < X->ncol; k++) {
                        if (d < fabs (X->ptr[i + k * X->nrow] - X->ptr[j + k * X->nrow])) {
                            d = fabs (X->ptr[i + k * X->nrow] - X->ptr[j + k * X->nrow]);
                        }
                    }
                }
                R->ptr[i + j * R->nrow] = minM / d;
            }
        }
    } 
    else {
        for (i = 0; i < X->nrow; i++) {
            for (j = 0; j < X->nrow; j++) {
                d = 0;
                if (opt == 14) {
                    for (k = 0; k < X->ncol; k++) {
                        d += pow (X->ptr[i + k * X->nrow] - X->ptr[j + k * X->nrow], 2);
                    }
                    d = sqrt (d);
                } 
                else if (opt == 15) {
                    for (k = 0; k < X->ncol; k++) {
                        d += fabs (X->ptr[i + k * X->nrow] - X->ptr[j + k * X->nrow]);
                    }
                } 
                else if (opt == 16) {
                    for (k = 0; k < X->ncol; k++) {
                        if (d < fabs (X->ptr[i + k * X->nrow] - X->ptr[j + k * X->nrow])) {
                            d = fabs (X->ptr[i + k * X->nrow] - X->ptr[j + k * X->nrow]);
                        }
                    }
                }
                R->ptr[i + j * R->nrow] = exp (-d);
            }
        }
    } 

    return UUL_OK;
}

