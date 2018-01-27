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

#define _SUCCESS_  (0)  /* 运行成功 */
#define _FAILTURE_ (1)  /* 运行失败 */
#define _ERROR_    (-1) /* 输入数据存在严重问题 */
#define _OVERFLOW_ (-2) /* 内存不足 */

#ifdef __cplusplus
extern "C" {
#endif

    /* --------------------------------------------------------------------------*/
    /**
     * @Synopsis  自定义数据类型
     */
    /* ----------------------------------------------------------------------------*/
    typedef int      Status;      /* 函数的返回结果：运行成功、运行失败、内存不足、输入数据存在严重问题 */
    typedef double   ElemType;    /* 浮点数类型 */
    typedef double  *ElemTypeP;   /* 浮点数指针类型 */
    typedef double **ElemTypePP;  /* 浮点数指针的指针类型 */
    typedef int      Integer;     /* 整数类型 */
    typedef int     *IntegerP;    /* 整数指针类型 */
    typedef struct {
        ElemType **ptr;
        Integer nrow;
        Integer ncol;
    } Matrix, *MatrixP;           /* 矩阵的数据结构 */

#ifdef __cplusplus
}
#endif

#endif /*!stdafx.h*/
