/************************************************************************************
Copyright	:
Author		: wangyoucao577@gmail.com
Date		: 2015-12-30
Description	: log file
************************************************************************************/

#ifndef __COMMON_LOG_H__
#define __COMMON_LOG_H__

#include "common_include.h"
extern "C" {

    COMMON_LIB_C_DLL_EXPORT int log_print(const char* format, ...);
}
#endif

