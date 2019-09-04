#include "common.h"
//Defining print_list function
int print_list (dlist *head)
{
	if (head == NULL)
	{
		return LIST_EMPTY;
	}
	else
	{
		printf("Elements are \n");
		while (head)
		{
			//Printing the data
			printf("%d --> ", head->data);
			head = head->next;
		}
		printf("\n\n");
	}
	return SUCCESS;
}

