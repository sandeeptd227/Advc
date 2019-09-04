#include "common.h"
//Defining insert at first function
int insert_at_first(dlist **head, dlist **tail, data_t data)
{
	//Creating a node
	dlist *new = malloc(sizeof(dlist));
	//Validation for the new node
	if (new == NULL)
	{
		return FAILURE;
	}
	//Updating the node values
	new->data = data;
	new->prev = NULL;
	new->next = *head;
	if (*head == NULL)
	{
		*tail = new;
	}
	if (new->next != NULL)
	{
		new->next->prev = new;
	}
	*head = new;
	return SUCCESS;
}

