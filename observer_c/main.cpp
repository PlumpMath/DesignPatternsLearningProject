/************************************************************************************
Copyright	:
Author		: wangyoucao577@gmail.com
Date		: 2015-12-19
Description	: main
************************************************************************************/

#include "common_include.h"
#include "common_log.h"
#include "subject.h"


struct my_info_subject_t
{
	int my_id;
	char my_description[128];
};

static int observer_A_update(void* param)
{
	assert(NULL != param);
	my_info_subject_t * my_info = (my_info_subject_t*)param;
	printf("%s:my new info----------->id:%d description:%s.\n", \
		__FUNCTION__, my_info->my_id, my_info->my_description);

	return NO_ERROR;
}

static int observer_B_update(void* param)
{
	assert(NULL != param);
	my_info_subject_t * my_info = (my_info_subject_t*)param;
	printf("%s:my new info----------->id:%d description:%s.\n", \
		__FUNCTION__, my_info->my_id, my_info->my_description);

	return NO_ERROR;
}

int main()
{
    printf("Observer test.\n");

	subject_model_t subject_mode;
	initialize_subject_model_t(&subject_mode);
	printf("subject model has been created.\n");

	subject_mode.attach_observer(&subject_mode, observer_A_update);
	printf("Observer A has been attached.\n");

	my_info_subject_t new_info;
	memset(&new_info, 0, sizeof(new_info));
	printf("Please Enter the new id:");
	scanf_s("%d", &new_info.my_id);
	printf("Please Enter the new description:");
	scanf_s("%s", new_info.my_description, _countof(new_info.my_description));
	subject_mode.notify(&subject_mode, &new_info);
	printf("\n\n");

	subject_mode.attach_observer(&subject_mode, observer_B_update);
	printf("Obsever B has been attached.\n");

	memset(&new_info, 0, sizeof(new_info));
	printf("Please Enter the new id:");
	scanf_s("%d", &new_info.my_id);
	printf("Please Enter the new description:");
	scanf_s("%s", new_info.my_description, _countof(new_info.my_description));
	subject_mode.notify(&subject_mode, &new_info);

    subject_mode.detach_observer(&subject_mode, observer_A_update);
    printf("Obsever A has been detached.\n");

    memset(&new_info, 0, sizeof(new_info));
    printf("Please Enter the new id:");
    scanf_s("%d", &new_info.my_id);
    printf("Please Enter the new description:");
    scanf_s("%s", new_info.my_description, _countof(new_info.my_description));
    subject_mode.notify(&subject_mode, &new_info);

	printf("\n\nPlease Enter any key to continue...\n");
    system("pause");

	return 0;
}