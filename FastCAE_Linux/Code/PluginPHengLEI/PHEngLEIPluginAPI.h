﻿#ifndef _PHENGLEIPLUGINAPI_H__
#define _PHENGLEIPLUGINAPI_H__

#include <QtCore/QtGlobal>


#if defined(PHENGLEIPLUGIN_API)
#define PHENGLEIPLUGINAPI Q_DECL_EXPORT
#else
#define PHENGLEIPLUGINAPI Q_DECL_IMPORT
#endif

#endif
