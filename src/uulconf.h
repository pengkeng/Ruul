#ifndef UULCONF_H
#define UULCONF_H

#define _SUCCESS_ (0)
#define _ERROR_ (1)
#define _OVERFLOW_ (-1)

typedef int _Status;
typedef double _ElemType;
typedef int _Integer;
typedef struct {
    _ElemType **ptr;
    int nrow;
    int ncol;
} _Matrix;

#endif /*!uulconf.h*/
