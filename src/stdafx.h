/**
 * @file stdafx.h
 * @Synopsis 模糊矩阵运算相关配置
 * @author Tokhta Horqin
 * @version 0.1.0
 * @date 2017-11-23
 */

#ifndef STDAFX_H
#define STDAFX_H

#include <stdlib.h>
#include <math.h>

#ifdef __cplusplus
extern "C" {
#endif

    /* --------------------------------------------------------------------------*/
    /**
     * @Synopsis  自定义数据类型
     */
    /* ----------------------------------------------------------------------------*/
    typedef int      uul__Status;      /* 函数的返回结果：运行成功、运行失败、内存不足、输入数据存在严重问题 */
    typedef double   uul__ElemType;    /* 浮点数类型 */
    typedef double  *uul__ElemTypeP;   /* 浮点数指针类型 */
    typedef double **uul__ElemTypePP;  /* 浮点数指针的指针类型 */
    typedef int      uul__Integer;     /* 整数类型 */
    typedef int     *uul__IntegerP;    /* 整数指针类型 */
    typedef struct {
        uul__ElemType **ptr;
        uul__Integer nrow;
        uul__Integer ncol;
    } uul__Matrix, *uul__MatrixP;           /* 矩阵的数据结构 */

#ifdef __cplusplus
}
#endif

#endif /*!stdafx.h*/
