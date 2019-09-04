#include "common.h"
//Defining insert at first function
int insert_at_first(tab_t **head, char_t filename)
{
	//Creating a node
	tab_t *new = malloc(sizeof(tab_t));
	//Validation for the new node
	if (new == NULL)
	{
		return FAILURE;
	}
	//Traverse till the end to check whether the file already esxits or not
	tab_t *temp = *head;
	while(temp)
	{
		if(strcmp(temp->flname, filename) == 0)
		{
			return FAILURE;
		}
		temp = temp->next_file;
	}
	//Updating the node values
	new->flname = filename;
	printf("%s\n", new->flname);
	new->next_file = *head;
	*head = new;
	return SUCCESS;
}

