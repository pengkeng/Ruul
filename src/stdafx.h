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
    typedef int    _Status;   /* 函数的返回结果：运行成功、运行失败、内存不足、输入数据存在严重问题 */
    typedef double _ElemType; /* 浮点数类型 */
    typedef int    _Integer;  /* 整数类型 */

    /* --------------------------------------------------------------------------*/
    /**
     * @Synopsis  矩阵的数据结构
     */
    /* ----------------------------------------------------------------------------*/
    typedef struct {
        _ElemType **ptr;
        int nrow;
        int ncol;
    } *_PMatrix, _Matrix;

    /* --------------------------------------------------------------------------*/
    /**
     * @Synopsis  矩阵的创建
     *
     * @Param M 矩阵
     * @Param nrow 矩阵的行数
     * @Param ncol 矩阵的列数
     *
     * @Returns   0—矩阵创建成功，1—矩阵创建失败，-2—内存不足
     */
    /* ----------------------------------------------------------------------------*/
    extern _Status matrixCreate (_PMatrix M, _Integer nrow, _Integer ncol);

    /* --------------------------------------------------------------------------*/
    /**
     * @Synopsis  矩阵的销毁
     *
     * @Param M 矩阵
     *
     * @Returns   0-矩阵销毁成功，1-矩阵销毁失败
     */
    /* ----------------------------------------------------------------------------*/
    extern _Status matrixDestroy (_PMatrix M);

#ifdef __cplusplus
}
#endif

#endif /*!stdafx.h*/
