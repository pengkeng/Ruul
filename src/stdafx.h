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

#define U_SUCCESS  (0)  /* 运行成功 */
#define U_FAILTURE (1)  /* 运行失败 */
#define U_ERROR    (-1) /* 输入数据存在严重问题 */
#define U_OVERFLOW (-2) /* 内存不足 */

#ifdef __cplusplus
extern "C" {
#endif

    /* --------------------------------------------------------------------------*/
    /**
     * @Synopsis  自定义数据类型
     */
    /* ----------------------------------------------------------------------------*/
    typedef int      U_Status;      /* 函数的返回结果：运行成功、运行失败、内存不足、输入数据存在严重问题 */
    typedef double   U_ElemType;    /* 浮点数类型 */
    typedef double  *U_ElemTypeP;   /* 浮点数指针类型 */
    typedef double **U_ElemTypePP;  /* 浮点数指针的指针类型 */
    typedef int      U_Integer;     /* 整数类型 */
    typedef int     *U_IntegerP;    /* 整数指针类型 */
    typedef struct {
        U_ElemType **ptr;
        U_Integer nrow;
        U_Integer ncol;
    } U_Matrix, *U_MatrixP;           /* 矩阵的数据结构 */

#ifdef __cplusplus
}
#endif

#endif /*!stdafx.h*/
