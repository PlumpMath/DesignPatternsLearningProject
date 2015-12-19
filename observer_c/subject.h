/************************************************************************************
Copyright	:
Author		: wangyoucao577@gmail.com
Date		: 2015-12-19
Description	: define my structs for the observer design
************************************************************************************/

#ifndef __MY_STRUCTS_H__
#define __MY_STRUCTS_H__

typedef int(*subject_update_callback)(void* param);

struct subject_t
{
	int my_id;
	char my_description[128];
};

struct subject_model_t
{
	void* callback_list;

	int (*attach_observer)(subject_update_callback update);
	int (*detach_observer)(subject_update_callback update);
	int (*detach_all)();
	int (*notify)(void* subject);
};

#endif // __MY_STRUCTS_H__


