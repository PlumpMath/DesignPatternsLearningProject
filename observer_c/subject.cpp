/************************************************************************************
Copyright	:
Author		: wangyoucao577@gmail.com
Date		: 2015-12-19
Description	: implementation of subject
************************************************************************************/


#include "common_include.h"
#include "list.h"
#include "subject.h"

static int attach_observer(struct subject_model_t* subject_model, subject_update_callback update)
{
	assert(NULL != subject_model);
	assert(NULL != update);

#ifdef CLASS_STYLE_STRUCT_LIST_T
    return subject_model->callback_list->push(subject_model->callback_list, (void*)update);
#else
    return list_t_push(subject_model->callback_list, (void*)update);
#endif
}

static int detach_observer(struct subject_model_t* subject_model, subject_update_callback update)
{
    assert(NULL != subject_model);
    assert(NULL != update);

#ifdef CLASS_STYLE_STRUCT_LIST_T
    return subject_model->callback_list->remove(subject_model->callback_list, (void*)update);
#else
    return list_t_remove(subject_model->callback_list, (void*)update);
#endif
}
static int detach_all(struct subject_model_t* subject_model)
{
	assert(NULL != subject_model);

#ifdef CLASS_STYLE_STRUCT_LIST_T
	return subject_model->callback_list->clear(subject_model->callback_list);
#else
    return list_t_clear(subject_model->callback_list);
#endif
}
static int notify(struct subject_model_t* subject_model, void* subject)
{
	assert(NULL != subject_model);
	assert(NULL != subject);

    int count = 0;
#ifdef CLASS_STYLE_STRUCT_LIST_T
    count = subject_model->callback_list->count(subject_model->callback_list);
#else
    count = list_t_count(subject_model->callback_list);
#endif
    for (int i = 0; i < count; ++i)
	{
		subject_update_callback curr_update_callback = NULL;
        int retval = NO_ERROR;
#ifdef CLASS_STYLE_STRUCT_LIST_T
        retval = subject_model->callback_list->peek(subject_model->callback_list, i, (void**)&curr_update_callback);
#else
        retval = list_t_peek(subject_model->callback_list, i, (void**)&curr_update_callback);
#endif
        assert(NO_ERROR == retval);

		int callback_retval = (curr_update_callback)(subject);
	}

	return NO_ERROR;
}


int initialize_subject_model_t(struct subject_model_t* subject_model)
{
	assert(NULL != subject_model);

	subject_model->callback_list = (struct list_t*)malloc(sizeof(struct list_t));
	initialize_list_t(subject_model->callback_list);

	//initialize interfaces
	subject_model->attach_observer = attach_observer;
	subject_model->detach_observer = detach_observer;
	subject_model->detach_all = detach_all;
	subject_model->notify = notify;

	return NO_ERROR;
}