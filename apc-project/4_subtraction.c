#include "common.h"
void subtraction(dlist **tail1, dlist **tail2, dlist **head3, dlist **tail3)
{
	//Declare variables
	dlist *temp1, *temp2, *borrow;
	data_t data;
	temp1 = *tail1;
	temp2 = *tail2;
	//Subtracting data of second node from first node
	while(1)
	{
		if(temp2)
		{
		borrow = temp1->prev;
			if((temp1->data == 0 || temp1->data < temp2->data) && temp2->data != 0)
			{
				temp1->data += 10000;
				while(borrow)
				{
					if(borrow->data)
					{
						(borrow->data)--;
						break;
					}
					else
					{
						borrow->data = 9999;
					}
					borrow = borrow->prev;
				}
			}
			data = temp1->data - temp2->data;
			insert_at_first(head3, tail3, data);
			temp1 = temp1->prev;
			temp2 = temp2->prev;
		}
		else
		{
			while(temp1)
			{
			data = temp1->data;
			insert_at_first(head3, tail3, data);
			temp1 = temp1->prev;
			}
			break;
		}
	}
}
