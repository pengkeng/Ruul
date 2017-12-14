#ifndef UUL_H
/**
 * @file uul.h
 * @Synopsis 模糊矩阵运算
 * @author Tokhta Horqin
 * @version 0.1
 * @date 2017-11-23
 */
#define UUL_H

#include "uulconf.h"

extern "C" {
    _Status matrixCreate (_Matrix &M, _Integer nrow, _Integer ncol);
    _Status matrixDestroy (_Matrix &M);

    /* --------------------------------------------------------------------------*/
    /**
     * @Synopsis  关系矩阵的合成
     *
     * @Param R 合成的关系矩阵
     * @Param R1 输入的关系矩阵R1
     * @Param R2 输入的关系矩阵R2
     */
    /* ----------------------------------------------------------------------------*/
    _Status matrixComposite (_Matrix &Rt, _Matrix R1, _Matrix R2);
    _Status matrixSimilar (_Matrix &R, _Matrix X, _Integer opt);
    _Status matrixStandard (_Matrix &Xstd, _Matrix X, _Integer opt);
}

#endif /*!uul.h*/
