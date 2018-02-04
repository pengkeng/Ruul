/**
 * @file uul.h
 * @Synopsis  模糊矩阵运算
 * @author Tokhta Horqin
 * @version 0.1.0
 * @date 2017-12-25
 */

#ifndef UUL_H
#define UUL_H

#include "stdafx.h"

#ifdef __cplusplus
extern "C" {
#endif

    /* --------------------------------------------------------------------------*/
    /**
     * @Synopsis  矩阵的创建
     *
     * @Param X 矩阵
     * @Param nrow 矩阵的行数
     * @Param ncol 矩阵的列数
     *
     * @Returns   0—矩阵创建成功，1—矩阵创建失败，-2—内存不足
     */
    /* ----------------------------------------------------------------------------*/
    extern U_Status U_create (U_MatrixP X, U_Integer nrow, U_Integer ncol);

    /* --------------------------------------------------------------------------*/
    /**
     * @Synopsis  矩阵的销毁
     *
     * @Param X 矩阵
     *
     * @Returns   0-矩阵销毁成功，1-矩阵销毁失败
     */
    /* ----------------------------------------------------------------------------*/
    extern U_Status U_destroy (U_MatrixP X);

    /* --------------------------------------------------------------------------*/
    /**
     * @Synopsis  关系矩阵的合成
     *
     * @Param Rt 合成的关系矩阵
     * @Param R1 输入的关系矩阵R1
     * @Param R2 输入的关系矩阵R2
     *
     * @Returns   0-矩阵合成成功，1-矩阵合成失败
     */
    /* ----------------------------------------------------------------------------*/
    extern U_Status U_bind (U_MatrixP Rt, U_MatrixP R1, U_MatrixP R2);

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
    extern U_Status U_dist (U_MatrixP R, U_MatrixP X, U_Integer opt);

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
    extern U_Status U_scale (U_MatrixP Xstd, U_MatrixP X, U_Integer opt);

#ifdef __cplusplus
}
#endif

#endif /*!uul.h*/
