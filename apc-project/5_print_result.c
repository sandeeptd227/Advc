#include "common.h"
//Defining print result function to print result in string
void print_result(dlist *head)
{
	//Declaring array for storing 4 characters
	char array[4] = {0};
	int num, digit, i;
	while(head)
	{
		num = head->data;
		i = 3;
		while(1)
		{
			digit = num % 10;
			array[i] = digit + 48;
			i--;
			num /= 10;
			if(i<0)
			{
				break;
			}
		}
		printf("%s", array);
		head = head->next;
	}
	
}
