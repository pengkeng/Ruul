/*
 *
 * 设论域
 * $\mathbf{U} = {{x}_{1}, x_{2}, \cdots, x_{n}}$, 
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

#include "uul.h"

/* --------------------------------------------------------------------------*/
/**
 * @Synopsis  相似矩阵的创建
 *
 * @Param R 创建的相似矩阵
 * @Param X 输入的数据矩阵
 * @Param opt 相似矩阵创建的方法
 *
 * @Returns   0—矩阵闭包创建成功，1—矩阵闭包创建失败，-1—输入数据矩阵存在严重问题
 */
/* ----------------------------------------------------------------------------*/
Status Dist (PMatrix R, PMatrix X, Integer opt)
{
    if (X->nrow <= 0 || X->ncol <= 0) {
        return _FAILTURE_;
    }
    if (R->nrow <= 0 || R->ncol <= 0) {
        return _FAILTURE_;
    }
    if (R->nrow != X->nrow || R->ncol != X->nrow) {
        return _FAILTURE_;
    }

    if (opt == 1) {
        ElemType temp;
        ElemType maxM;

        maxM = 0;
        for (Integer i = 0; i < X->nrow; i++) {
            for (Integer j = 0; j < X->nrow; j++) {
                if (i != j) {
                    temp = 0;
                    for (Integer k = 0; k < X->ncol; k++) {
                        temp += *(*(X->ptr + i) + k) * *(*(X->ptr + j) + k);
                    }
                    if (maxM < temp) {
                        maxM = temp;
                    } 
                    else if (maxM < -temp) {
                        maxM = -temp;
                    }
                }
            }
        }
        maxM += 1;
        for (Integer i = 0; i < X->nrow; i++) {
            for (Integer j = 0; j < X->nrow; j++) {
                if (i == j) {
                    *(*(R->ptr + i)+ j) = 1;
                } 
                else {
                    *(*(R->ptr + i) + j) = 0;
                    for (Integer k = 0; k < X->ncol; k++) {
                        *(*(R->ptr + i)+ j) += *(*(X->ptr + i)+ k) * *(*(X->ptr + j) + k);
                    }
                    *(*(R->ptr + i) + j) /= maxM;
                    if (*(*(R->ptr + i)+ j) < 0) {
                        *(*(R->ptr + i) + j) = (*(*(R->ptr + i)+ j) + 1) / 2;
                    }
                }
            }
        } 
    } 
    else if (opt == 2) {
        ElemType xi, xj, s;

        for (Integer i = 0; i < X->nrow; i++) {
            for (Integer j = 0; j < X->nrow; j++) {
                xi = 0; xj = 0;
                for (Integer k = 0; k < X->ncol; k++) {
                    xi += *(*(X->ptr + i) + k) * *(*(X->ptr + i) + k);
                    xj += *(*(X->ptr + j) + k) * *(*(X->ptr + j)+ k);
                }
                s = sqrt (xi * xj);
                *(*(R->ptr + i) + j) = 0;
                for (Integer k = 0; k < X->ncol; k++) {
                    *(*(R->ptr + i) + j) += 
                        *(*(X->ptr + i) + k) * *(*(X->ptr + j) + k);
                }
                *(*(R->ptr + i) + j) /= s;
                if (*(*(R->ptr + i) + j) <  0) {
                    *(*(R->ptr + i)+ j) = (*(*(R->ptr + i)+ j) + 1) / 2;
                }
            }
        }
    }
    else if (opt == 3) {
        ElemType xi, xj, s;
        ElemType xis, xjs;

        for (Integer i = 0; i < X->nrow; i++) {
            for (Integer j = 0; j < X->nrow; j++) {
                xi = 0; xj = 0;
                for (Integer k = 0; k < X->ncol; k++) {
                    xi += *(*(X->ptr + i) + k);
                    xj += *(*(X->ptr + j) + k);
                }
                xi /= X->ncol; 
                xj /= X->ncol;
                xis = 0; xjs = 0;
                for (Integer k = 0; k < X->ncol; k++) {
                    xis += pow (*(*(X->ptr + i) + k) - xi, 2);
                    xjs += pow (*(*(X->ptr + j) + k) - xj, 2);
                }
                s = sqrt (xis * xjs);
                *(*(R->ptr + i) + j) = 0;
                for (Integer k = 0; k < X->ncol; k++) {
                    *(*(R->ptr + i) + j) += 
                        fabs ((*(*(X->ptr + i) + k) - xi) * (*(*(X->ptr + j) + k) - xj));
                }
                *(*(R->ptr + i) + j) /= s;
            }
        }
    } 
    else if (opt == 4) {
        ElemType xk, sk;
        ElemType exponent;

        for (Integer i = 0; i < X->nrow; i++) {
            for (Integer j = 0; j < X->nrow; j++) {
                *(*(R->ptr + i) + j) = 0;
                for (Integer k = 0; k < X->ncol; k++) {
                    xk= 0;
                    for (Integer z = 0; z < X->nrow; z++) {
                        xk += *(*(X->ptr + z) + k);
                    }
                    xk /= X->nrow;
                    sk = 0;
                    for (Integer z = 0; z < X->nrow; z++) {
                        sk += pow(*(*(X->ptr + z) + k) - xk, 2);
                    }                    
                    sk /= X->nrow;
                    exponent = 
                        -0.75 * pow (*(*(X->ptr + i) + k) - *(*(X->ptr + j) + k), 2) / sk;
                    *(*(R->ptr + i) + j) += exp (exponent);
                }
                *(*(R->ptr + i) + j) /= X->ncol;
            }
        }
    } 
    else if (opt <= 7) {
        ElemType fz, fm;

        for (Integer i = 0; i < X->nrow; i++) {
            for (Integer j = 0; j < X->nrow; j++) {
                fz = 0; 
                fm = 0;
                for (Integer k = 0; k < X->ncol; k++) {
                    if (*(*(X->ptr + j) + k) < 0) {
                        return _ERROR_;
                    }
                    if (*(*(X->ptr + j) + k) < *(*(X->ptr + i) + k)) {
                        fz += *(*(X->ptr + i) + k);
                    } 
                    else {
                        fz += *(*(X->ptr + j) + k);
                    }
                }
                if (opt == 5) {
                    for (Integer k = 0; k < X->ncol; k++) {
                        if (*(*(X->ptr + i) + k) > *(*(X->ptr + j) + k)) {
                            fm += *(*(X->ptr + i) + k);
                        } 
                        else {
                            fm += *(*(X->ptr + j) + k);
                        } 
                    }
                } 
                else if (opt == 6) {
                    for (Integer k = 0; k < X->ncol; k++) {
                        fm += (*(*(X->ptr + i) + k) + *(*(X->ptr + j) + k)) / 2;
                    }
                } 
                else if (opt == 7) {
                    for (Integer k = 0; k < X->ncol; k++) {
                        fm += sqrt (*(*(X->ptr + i) + k) * *(*(X->ptr + j) + k));
                    }
                }
                *(*(R->ptr + i) + j) = fz / fm;
            }
        }
    } 
    else if (opt <= 10) {
        ElemType d;
        ElemType c;

        c = 0;
        for (Integer i = 0; i < X->nrow; i++) {
            for (Integer j = i + 1; j < X->nrow; j++) {
                d = 0;
                if (opt == 8) {
                    for (Integer k = 0; k < X->ncol; k++) {
                        d += pow ((*(*(X->ptr + i) + k) - *(*(X->ptr + j) + k)), 2);
                    }
                    d = sqrt (d);
                } 
                else if (opt == 9) {
                    for (Integer k = 0; k < X->ncol; k++) {
                        d += fabs (*(*(X->ptr + i) + k) - *(*(X->ptr + j) + k));
                    }
                } 
                else if (opt == 10) {
                    for (Integer k = 0; k < X->ncol; k++) {
                        if (d < fabs (*(*(X->ptr + i) + k) - *(*(X->ptr + j) + k))) {
                            d = fabs (*(*(X->ptr + i) + k) - *(*(X->ptr + j) + k));
                        }
                    }
                }
                if (c < d) {
                    c = d;
                }
            }
        }
        c = 1.0 / (1.0 + c);
        for (Integer i = 0; i < X->nrow; i++) {
            for (Integer j = 0; j < X->nrow; j++) {
                d = 0;
                if (opt == 8) {
                    for (Integer k = 0; k < X->ncol; k++) {
                        d += pow (*(*(X->ptr + i) + k) -*(*(X->ptr + j) + k) , 2);
                    }
                    d = sqrt (d);
                } 
                else if (opt == 9) {
                    for (Integer k = 0; k < X->ncol; k++) {
                        d += fabs (*(*(X->ptr + i) + k) - *(*(X->ptr + j) + k));
                    }
                } 
                else if (opt == 10) {
                    for (Integer k = 0; k < X->ncol; k++) {
                        if (d < fabs (*(*(X->ptr + i) + k) - *(*(X->ptr + j) + k))) {
                            d = fabs (*(*(X->ptr + i) + k) - *(*(X->ptr + j) + k));
                        }
                    }
                }
                *(*(R->ptr + i) + j) = 1 - c * d;
            }
        }
    } 
    else if (opt <= 13) {
        ElemType minM;
        ElemType d;

        minM = 1E+6;
        for (Integer i = 0; i < X->nrow; i++) {
            for (Integer j = i + 1; j < X->nrow; j++) {
                d = 0;
                if (opt == 11) {
                    for (Integer k = 0; k < X->ncol; k++) {
                        d += pow (*(*(X->ptr + i) + k) - *(*(X->ptr + j) + k), 2);
                    }
                    d = sqrt (d);
                } 
                else if (opt == 12) {
                    for (Integer k = 0; k < X->ncol; k++) {
                        d += fabs (*(*(X->ptr + i) + k) - *(*(X->ptr + j) + k));
                    }
                } 
                else if (opt == 13) {
                    for (Integer k = 0; k < X->ncol; k++) {
                        if (d < fabs (*(*(X->ptr + i) + k) - *(*(X->ptr + j) + k))) {
                            d = fabs (*(*(X->ptr + i) + k) - *(*(X->ptr + j) + k));
                        }
                    }
                }
                if (minM > d) {
                    minM = d;
                }
            }
        }
        minM *= 0.9999;
        for (Integer i = 0; i < X->nrow; i++) {
            for (Integer j = 0; j < X->nrow; j++) {
                d = 0;
                if (i == j) {
                    *(*(R->ptr + i) + j) = 1;
                    continue;
                }
                if (opt == 11) {
                    for (Integer k = 0; k < X->ncol; k++) {
                        d += pow (*(*(X->ptr + i) + k)- *(*(X->ptr + j) + k), 2);
                    }
                    d = sqrt(d);
                } 
                else if (opt == 12) {
                    for (Integer k = 0; k < X->ncol; k++) {
                        d += fabs (*(*(X->ptr + i) + k) - *(*(X->ptr + j) + k));
                    }
                } 
                else if (opt == 13) {
                    for (Integer k = 0; k < X->ncol; k++) {
                        if (d < fabs (*(*(X->ptr + i) + k) - *(*(X->ptr + j) + k))) {
                            d = fabs (*(*(X->ptr + i) + k) - *(*(X->ptr + j) + k));
                        }
                    }
                }
                *(*(R->ptr + i) + j) = minM / d;
            }
        }
    } 
    else if (opt <= 16) {
        ElemType d;

        for (Integer i = 0; i < X->nrow; i++) {
            for (Integer j = 0; j < X->nrow; j++) {
                d = 0;
                if (opt == 14) {
                    for (Integer k = 0; k < X->ncol; k++) {
                        d += pow (*(*(X->ptr + i) + k) - *(*(X->ptr + j) + k), 2);
                    }
                    d = sqrt (d);
                } 
                else if (opt == 15) {
                    for (Integer k = 0; k < X->ncol; k++) {
                        d += fabs (*(*(X->ptr + i) + k) - *(*(X->ptr + j) + k));
                    }
                } 
                else if (opt == 16) {
                    for (Integer k = 0; k < X->ncol; k++) {
                        if (d < fabs (*(*(X->ptr + i) + k) - *(*(X->ptr + j) + k))) {
                            d = fabs (*(*(X->ptr + i) + k) - *(*(X->ptr + j) + k));
                        }
                    }
                }
                *(*(R->ptr + i) + j) = exp (-d);
            }
        }
    } 
    else {
        return _FAILTURE_;
    }

    return _SUCCESS_;
}

