/************************************************************************************
Copyright	:
Author		: wangyoucao577@gmail.com
Date		: 2015-12-19
Description	: implementation of subject
************************************************************************************/


#include "common_include.h"
#include "list.h"
#include "subject.h"

int initialize_subject_model_t(struct subject_model_t* subject_model)
{
	assert(NULL != subject_model);

	initialize_list_t(subject_model->callback_list);


	return NO_ERROR;
}