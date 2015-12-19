/************************************************************************************
Copyright	:
Author		: wangyoucao577@gmail.com
Date		: 2015-12-19
Description	: structs and interfaces of the list
************************************************************************************/

#include "common_include.h"
#include "list.h"

static int list_t_push(struct list_t *list, node_t* node)
{
	assert(NULL != list);
	assert(NULL != node);

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

static int list_t_pop(struct list_t *list, node_t** node)
{
	assert(NULL != list);	
	assert(NULL != node && NULL == *node);

	*node = list->head;
	if (NULL == *node)
	{
		return COMMON_ERROR_CODE_FIFO_EMPTY;
	}

	list->head = list->head->next;
	return NO_ERROR;

}

static int list_t_peek(struct list_t *list, int index, node_t** node)
{
	assert(NULL != list);
	assert(NULL != node && NULL == *node);
	assert(index >= 0);

	if (index >= list->count(list))
	{
		return COMMON_ERROR_CODE_OUT_OF_RANGE;
	}

	int curr_node_index = 0;
	struct node_t* curr_node = list->head;
	do 
	{
		if (curr_node_index == index)
		{
			*node = curr_node;
			break;
		}
		curr_node = curr_node->next;
		++curr_node_index;
	} while (NULL != curr_node);

	return NO_ERROR;
}

static int list_t_clear(struct list_t *list)
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

static int list_t_count(struct list_t *list)
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


int initialize_list_t(struct list_t *list)
{
	assert(NULL != list);

	list->head = NULL;

	//Initialize the interfaces
	list->push = list_t_push;
	list->pop = list_t_pop;
	list->peek = list_t_peek;
	list->clear = list_t_clear;
	list->count = list_t_count;

	return NO_ERROR;
}

