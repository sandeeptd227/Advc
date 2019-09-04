include "common.h"
int addition(dlist **tail1, dlist **tail2, dlist **head3, dlist **tail3)
{
	//Declare variables
	dlist *temp1, *temp2;
	data_t data, status,carry = 0;
	temp1 = *tail1;
	temp2 = *tail2;
	//Add one node from each list at a time and send the result to resultant list
	while (temp1 && temp2)
	{
		data = temp1->data + temp2->data;
		//Check for data if it crosses 10000 
		//If yes make carry 1
		if (data >= 10000)
		{
			data -= 10000;
			status = insert_at_first(head3, tail3, data + carry);
			carry = 1;
		}
		else
		{
			status = insert_at_first(head3, tail3, data + carry);
			carry = 0;
		}
		temp1 = temp1->prev;
		temp2 = temp2->prev;
	}
	//If 2nd number reaches end copy all first number elements to result
	while (temp1)
	{
		data = temp1->data;
		status = insert_at_first(head3, tail3, data + carry);
		carry = 0;
		temp1 = temp1->prev;
	}
	//If 1st number reaches end copy all first number elements to result
	while (temp2)
	{
		data = temp2->data;
		status = insert_at_first(head3, tail3, data + carry);
		carry = 0;
		temp2 = temp2->prev;
	}
	//If both reaches end and if the carry is 1
	if(carry == 1)
	{
		status = insert_at_first(head3, tail3, 1);
		carry = 0;
	}
}
