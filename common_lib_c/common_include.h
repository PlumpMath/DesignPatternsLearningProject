/************************************************************************************
Copyright	: 
Author		: wangyoucao577@gmail.com
Date		: 2015-12-19
Description	: include most of the .h files here, easy to use
************************************************************************************/

#ifndef __COMMON_INCLUDE_H__
#define __COMMON_INCLUDE_H__

//from sys
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <fcntl.h>
#include <errno.h>

#if defined(WIN32)
//TODO: add headers which only windows have here
#include <windows.h>
#elif defined(linux)
//TODO: add headers which only linux have here
#else
//TODO: maybe other platforms
#endif

#endif // !__COMMON_INCLUDE_H__
