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

	struct node_t* new_node = (struct node_t*)malloc(sizeof(struct node_t));
	assert(NULL != new_node);

	new_node->data = update;
	new_node->next = NULL;

	return subject_model->callback_list->push(subject_model->callback_list, new_node);
}

static int detach_observer(struct subject_model_t* subject_model, subject_update_callback update)
{
    assert(NULL != subject_model);
    assert(NULL != update);

    struct node_t new_node;
    new_node.data = update;
    new_node.next = NULL;

    struct node_t* remove_node = NULL;
    int ret = subject_model->callback_list->remove(subject_model->callback_list, &new_node, &remove_node);
    if (NO_ERROR == ret)
    {
        free(remove_node);
        remove_node = NULL;
    }
    else
    {
        return ret;
    }

    return NO_ERROR;
}
static int detach_all(struct subject_model_t* subject_model)
{
	assert(NULL != subject_model);

	return subject_model->callback_list->clear(subject_model->callback_list);
}
static int notify(struct subject_model_t* subject_model, void* subject)
{
	assert(NULL != subject_model);
	assert(NULL != subject);

	int count = subject_model->callback_list->count(subject_model->callback_list);
	for (int i = 0; i < count; ++i)
	{
		struct node_t* curr_node = NULL; 
		int retval = subject_model->callback_list->peek(subject_model->callback_list, i, &curr_node);
		assert(NO_ERROR == retval);

		int callback_retval = ((subject_update_callback)(curr_node->data))(subject);
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