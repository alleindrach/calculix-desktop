﻿#ifndef _GEOMETRYDATAEXCHANGEAPI_H_
#define _GEOMETRYDATAEXCHANGEAPI_H_

#include <QtCore/QtGlobal>


#if defined(GEOMETRYDATAEXCHANGE_API)
#define GEOMETRYDATAEXCHANGEAPI Q_DECL_EXPORT
#else
#define GEOMETRYDATAEXCHANGEAPI Q_DECL_IMPORT
#endif

#endif
