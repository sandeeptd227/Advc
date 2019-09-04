/*
Title       : Arithmetic Precision calculator / Bignum calculator
Author      : Sandeep
Date        : 6 August 2019
Description : Perform arithmetic operations for big numbers
Input       : Two big numbers and operator
Output      : Based on operator
 */
#include "common.h"
int main(int argc, char *argv[])
{
	dlist *head1 = NULL;
	dlist *tail1 = NULL;
	dlist *head2 = NULL;
	dlist *tail2 = NULL;
	dlist *head3 = NULL;
	dlist *tail3 = NULL;
	//Declare variables
	size_t i, j;
	char delim;
	//Check for operator
	for (i = 0; argv[1][i]; i++)
	{
		if (argv[1][i] == '+' || argv[1][i] == '-')
		{
			delim = argv[1][i];
			break;
		}
	}
	//Getting two operands from the given string by splitting based on operator
	char *token1 = strtok(argv[1] , &delim);
	char *token2 = strtok(NULL, &delim);
	//Declaring variables for two string lengths
	size_t length1 = strlen(token1);
	size_t length2 = strlen(token2);
	//Allocating memory for for two integer arrays
	int *array1 = (int *)calloc(length1, sizeof(int));
	int *array2 = (int *)calloc(length2, sizeof(int));
	//Converting character array to integer array
	for (i = 0; i < length1; i++)
	{
		array1[i] = token1[i] - 48;
	}
	for (i = 0; i < length2; i++)
	{
		array2[i] = token2[i] - 48;
	}
	//Making 4digits to 4digit number
	four_digits(array1, length1, &head1, &tail1);
	four_digits(array2, length2, &head2, &tail2);
	switch (delim)
	{
		case '+':
			addition(&tail1, &tail2, &head3, &tail3);
			print_list(head3);
			print_result(head3);
			break;
		case '-':
			if(length1 < length2)
			{
				printf("-");
				subtraction(&tail2, &tail1, &head3, &tail3);
			}
			else if (length1 > length2)
			{
				subtraction(&tail1, &tail2, &head3, &tail3);
			}
			else
			{
				//Comparing each digit
				for (i = 0; i < length1; i++)
				{
					if(array1[i] > array2[i])
					{
						subtraction(&tail1, &tail2, &head3, &tail3);
						break;
					}
					if(array1[i] < array2[i])
					{
						printf("-");
						subtraction(&tail2, &tail1, &head3, &tail3);
						break;
					}
					subtraction(&tail1, &tail2, &head3, &tail3);
				}
			}
			//	print_list(head3);
			print_result(head3);
			break;
		default: printf("Invalid operator\n");
	}
	return 0;
}
