/**
 * @file uul.h
 * @Synopsis  模糊矩阵运算
 * @author Tokhta Horqin
 * @version 0.2.1
 * @date 2018-02-14
 */

#ifndef UUL_H
#define UUL_H

#define UUL_OK    1               /* 运行成功 */
#define UUL_ERROR 0               /* 运行失败 */

/* --------------------------------------------------------------------------*/
/**
 * @Synopsis  定义数据类型
 */
/* ----------------------------------------------------------------------------*/
typedef int      uul__Status;      /* 函数的返回结果：运行成功、运行失败 */
typedef double   uul__ElemType;    /* 浮点数类型 */
typedef int      uul__Integer;     /* 整数类型 */
typedef struct {                   /* 矩阵的数据结构 */
    uul__ElemType *ptr;
    uul__Integer nrow;
    uul__Integer ncol;
} uul__Matrix, *uul__MatrixP; 

/* --------------------------------------------------------------------------*/
/**
 * @Synopsis  矩阵的创建
 *
 * @Param X 矩阵
 * @Param nrow 矩阵的行数
 * @Param ncol 矩阵的列数
 *
 * @Returns   UUL_OK—矩阵创建成功，UUL_ERROR—矩阵创建失败
 */
/* ----------------------------------------------------------------------------*/
extern uul__Status uul__create (uul__MatrixP X, uul__Integer nrow, uul__Integer ncol);

/* --------------------------------------------------------------------------*/
/**
 * @Synopsis  矩阵的销毁
 *
 * @Param X 矩阵
 *
 * @Returns   UUL_OK-矩阵销毁成功，UUL_ERROR-矩阵销毁失败
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
 * @Returns   UUL_OK-矩阵合成成功，UUL_ERROR-矩阵合成失败
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
 * @Returns   UUL_OK—矩阵闭包创建成功，UUL_ERROR—矩阵闭包创建失败
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
 * @Returns   UUL_OK-矩阵标准化成功，UUL_ERROR—矩阵标准化失败
 */
/* ----------------------------------------------------------------------------*/
extern uul__Status uul__scale (uul__MatrixP Xstd, uul__MatrixP X, uul__Integer opt);

#endif /* uul.h */
