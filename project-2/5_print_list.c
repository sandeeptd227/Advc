#include "common.h"
//Defining print_list function
int print_list (tab_t *head)
{
	if (head == NULL)
	{
		return FAILURE;
	}
	else
	{
		printf("Elements are \n");
		while (head)
		{
			//Printing the data
			printf("%s --> ", head->flname);
			head = head->next_file;
		}
		printf("\n\n");
	}
	return SUCCESS;
}

