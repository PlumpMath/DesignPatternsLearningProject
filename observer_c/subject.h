/************************************************************************************
Copyright	:
Author		: wangyoucao577@gmail.com
Date		: 2015-12-19
Description	: define my structs for the observer design
************************************************************************************/

#ifndef __SUBJECT_H__
#define __SUBJECT_H__

typedef int(*subject_update_callback)(void* param);

struct subject_model_t
{
	struct list_t* callback_list;

	int (*attach_observer)(struct subject_model_t* subject_model, subject_update_callback update);
	int (*detach_observer)(struct subject_model_t* subject_model, subject_update_callback update);
	int (*detach_all)(struct subject_model_t* subject_model);
	int (*notify)(struct subject_model_t* subject_model, void* subject);
};

int initialize_subject_model_t(struct subject_model_t* subject_model);



struct my_subject_t
{
	int my_id;
	char my_description[128];
};


#endif // __SUBJECT_H__


