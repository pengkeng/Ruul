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
     * @Returns   0—矩阵创建成功，1—矩阵创建失败，3—内存不足
     */
    /* ----------------------------------------------------------------------------*/
    extern uul__Status uul__create (uul__MatrixP X, uul__Integer nrow, uul__Integer ncol);

    /* --------------------------------------------------------------------------*/
    /**
     * @Synopsis  矩阵的销毁
     *
     * @Param X 矩阵
     *
     * @Returns   0-矩阵销毁成功，1-矩阵销毁失败
     */
    /* ----------------------------------------------------------------------------*/
    extern uul__Status uul__destroy (uul__MatrixP X);

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
    extern uul__Status uul__bind (uul__MatrixP Rt, uul__MatrixP R1, uul__MatrixP R2);

    /* --------------------------------------------------------------------------*/
    /**
     * @Synopsis  相似矩阵的创建
     *
     * @Param R 创建的相似矩阵
     * @Param X 输入的数据矩阵
     * @Param opt 相似矩阵创建的方法
     *
     * @Returns   0—矩阵闭包创建成功，1—矩阵闭包创建失败
     */
    /* ----------------------------------------------------------------------------*/
    extern uul__Status uul__dist (uul__MatrixP R, uul__MatrixP X, uul__Integer opt);

    /* --------------------------------------------------------------------------*/
    /**
     * @Synopsis  标准矩阵的创建
     *
     * @Param Xstd 创建的标准矩阵
     * @Param X 输入的数据矩阵
     * @Param opt 标准矩阵创建的方法
     *
     * @Returns   0-矩阵标准化成功，1—矩阵标准化失败
     */
    /* ----------------------------------------------------------------------------*/
    extern uul__Status uul__scale (uul__MatrixP Xstd, uul__MatrixP X, uul__Integer opt);

#ifdef __cplusplus
}
#endif

#endif /*!uul.h*/
