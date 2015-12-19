/************************************************************************************
Copyright	:
Author		: wangyoucao577@gmail.com
Date		: 2015-12-19
Description	: structs and interfaces of the list
************************************************************************************/

#ifndef __COMMON_ERROR_CODE_H__
#define __COMMON_ERROR_CODE_H__

enum COMMON_ERROR_CODE
{
	NO_ERROR = 0,

	COMMON_ERROR_CODE_UNAVAILABLE = 1-001,

	COMMON_ERROR_CODE_OUT_OF_RANGE = 20001,
	COMMON_ERROR_CODE_FIFO_EMPTY,
};

#endif