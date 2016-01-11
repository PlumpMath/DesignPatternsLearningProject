/************************************************************************************
Copyright	:
Author		: wangyoucao577@gmail.com
Date		: 2015-12-19
Description	: structs and interfaces of the list
************************************************************************************/

#include "common_include.h"
#include "list.h"

STATIC_FUNC int list_t_count(struct list_t *list)
{
    assert(NULL != list);

    int count = 0;
    struct node_t* current_node = list->head;
    while (NULL != current_node)
    {
        ++count;
        current_node = current_node->next;
    }
    return count;
}

STATIC_FUNC int list_t_push(struct list_t *list, void* data)
{
	assert(NULL != list);
	assert(NULL != data);

	struct node_t* node = (struct node_t*)malloc(sizeof(struct node_t));
	assert(NULL != node);

	node->data = data;
	node->next = NULL;

	if (NULL == list->head)
	{
		list->head = node;
	}
	else
	{
		struct node_t* last_node = list->head;
		while (NULL != last_node->next)
		{
			last_node = last_node->next;
		}

		last_node->next = node;
	}

	return NO_ERROR;
}

STATIC_FUNC int list_t_pop(struct list_t *list, void** data)
{
	assert(NULL != list);	
	assert(NULL != data && NULL == *data);

	if (NULL == list->head)
	{
		return COMMON_ERROR_CODE_FIFO_EMPTY;
	}

	struct node_t* node = list->head;
	list->head = list->head->next;

	*data = node->data;

	free(node);
	node = NULL;

	return NO_ERROR;

}

STATIC_FUNC int list_t_remove(struct list_t *list, void* data)
{
    assert(NULL != list);
    assert(NULL != data);

    node_t* curr_node = list->head;
    node_t* prev_node = NULL;
    while (NULL != curr_node)
    {
        if (curr_node->data == data)
        {
            if (curr_node == list->head)
            {
                list->head = list->head->next;
            }
            else
            {
                prev_node->next = curr_node->next;
            }

			free(curr_node);
			curr_node = NULL;

            return NO_ERROR;
        }
        
        prev_node = curr_node;
        curr_node = curr_node->next;
    }

    return COMMON_ERROR_CODE_NO_SPECIFIED_DATA;
}

STATIC_FUNC int list_t_peek(struct list_t *list, int index, void** data)
{
	assert(NULL != list);
	assert(NULL != data && NULL == *data);
	assert(index >= 0);

	if (index >= list_t_count(list))
	{
		return COMMON_ERROR_CODE_OUT_OF_RANGE;
	}

	int curr_node_index = 0;
	struct node_t* curr_node = list->head;
	do 
	{
		if (curr_node_index == index)
		{
			*data = curr_node->data;
			break;
		}
		curr_node = curr_node->next;
		++curr_node_index;
	} while (NULL != curr_node);

	return NO_ERROR;
}

STATIC_FUNC int list_t_clear(struct list_t *list)
{
	assert(NULL != list);
	
	struct node_t* current_node = list->head;
	while (NULL != current_node)
	{
		list->head = list->head->next;

		free(current_node);

		current_node = list->head;
	}

	return NO_ERROR;

}


int initialize_list_t(struct list_t *list)
{
	assert(NULL != list);

	list->head = NULL;

#ifdef CLASS_STYLE_STRUCT_LIST_T

    //Initialize the interfaces
    list->push = list_t_push;
    list->pop = list_t_pop;
    list->remove = list_t_remove;
    list->peek = list_t_peek;
    list->clear = list_t_clear;
    list->count = list_t_count;

#endif // CLASS_STYLE_STRUCT_LIST_T

	return NO_ERROR;
}

