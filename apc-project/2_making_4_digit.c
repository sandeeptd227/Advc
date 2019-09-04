#include "common.h"
void four_digits(int array[], size_t length, dlist **head, dlist **tail)
{
	data_t num = 0, count = 0;
	int x = 0, status;
	size_t i;
	//Making 4 digit numbers 
	for (i = length - 1; i >= 0; i--)
	{
		num = num + (array[i] * pow(10, x));
		count++;
		x++;
		if (count == 4 || i == 0)
		{
			//Sending number to the node
			status = insert_at_first(head, tail, num);
			num = 0;
			x = 0;
			count = 0;
			if (i == 0)
			{
				return;
			}
		}
	}
}
