﻿#ifndef SOLUTIONDATAIO_GLOBAL_H
#define SOLUTIONDATAIO_GLOBAL_H

#include <QtCore/qglobal.h>

#ifdef SOLUTIONDATAIO_LIB
# define SOLUTIONDATAIO_EXPORT Q_DECL_EXPORT
#else
# define SOLUTIONDATAIO_EXPORT Q_DECL_IMPORT
#endif

#endif // SOLUTIONDATAIO_GLOBAL_H
