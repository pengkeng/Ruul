/**
 * @file uulconf.h
 * @Synopsis  模糊矩阵运算相关配置信息
 * @author Tokhta Horqin
 * @version 0.1.0
 * @date 2017-12-18
 */
#ifndef UULCONF_H
#define UULCONF_H

#define _SUCCESS_  (0)  /* 运行成功 */
#define _FAILTURE_ (1)  /* 运行失败 */
#define _ERROR_    (-1) /* 输入数据存在严重问题 */
#define _OVERFLOW_ (-2) /* 内存不足 */

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
} _Matrix;

#endif /*!uulconf.h*/
