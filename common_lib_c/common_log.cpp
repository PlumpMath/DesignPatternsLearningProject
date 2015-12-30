/************************************************************************************
Copyright	:
Author		: wangyoucao577@gmail.com
Date		: 2015-12-30
Description	: log file
************************************************************************************/

#include "common_log.h"

int log_print(const char* format, ...)
{
    char printf_buf[512] = { '\0' };

    ////analyse the data
    va_list  arg;
    //int done = 0;
    va_start(arg, format);
    //int done = vsnprintf(printf_buf, sizeof(printf_buf) - 1, format, arg);
    va_end(arg);

    return printf(format, arg);
}