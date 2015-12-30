/************************************************************************************
Copyright	:
Author		: wangyoucao577@gmail.com
Date		: 2015-12-19
Description	: structs and interfaces of the list
************************************************************************************/

#ifndef __LIST_H__
#define __LIST_H__

#include "common_include.h"
extern "C" {

    struct list_t
    {
        /**
        * push
        * @description: append the new node to the end of the list
        * @param data[IN]: the new data
        * @return 0 if success, otherwise failed and indicate the error code
        */
        int(*push)(struct list_t *list, void* data);

        /**
        * pop
        * @description: get the first node out and then remove it from the list
        * @param data[OUT]: pointer of the out data
        * @return 0 if success, otherwise failed and indicate the error code
        */
        int(*pop)(struct list_t *list, void** data);

        /**
        * remove
        * @description: remove the specified node from the list, and just take it out
        *   users should consider to free the memory.
        * @param data[IN]: if the node contains this data, then going to remove it
        * @return 0 if success, otherwise failed and indicate the error code
        */
        int(*remove)(struct list_t *list, void* data);

        /**
        * peek
        * @description: get the node indicated by the index, just have a look or do something
        * @param index[IN]: the index of the node in the list
        * @param data[OUT]: pointer of the out data
        * @return 0 if success, otherwise failed and indicate the error code
        */
        int(*peek)(struct list_t *list, int index, void** data);

        /**
        * clear
        * @description: clear all the nodes of the list
        * @return 0 if success, otherwise failed and indicate the error code
        */
        int(*clear)(struct list_t *list);

        /**
        * count
        * @return how many nodes in the list
        */
        int(*count)(struct list_t *list);

        //--------------------------------------------------------
        struct node_t* head;
    };

    /**
    * initialize_list_t
    * @description: initialize the list
    * @return 0 if success, otherwise failed and indicate the error code
    */
    COMMON_LIB_C_DLL_EXPORT int initialize_list_t(struct list_t *list);

}

#endif
