/* 
Title       : 20_prepost.c 
Author      : Sandeep
Date        : 17 June 2019
Description : Pre incrementing and post incrementing using bitwise operators
Input       : Any number
output      : Result after pre and post incrementing of the given number  
 */

#include <stdio.h>
#include <stdlib.h>

//Declaring function
void increment(int *);

int main()
{

	//Declaring the variables 
	int num, res, choice, status;
	char option;
	do
	{
		//Clear the screen
		system("clear");
		//Enter the number and store it in the variable
		printf("Enter any number : ");
		status = scanf("%d", &num);
		if (status != 1)
		{
			printf("Invalid input\n");
			return 0;
		}

		printf("Select an option\n1.Pre increment\n2.Post increment\n");
		scanf("%d", &choice);
		switch (choice)
		{
			case 1 :
				//Calling pre increment function
				increment(&num);
				res = num;
				printf("res = ++num\nres = %d\t num = %d\n", res, num);
				break;
			case 2 :
				//Calling post increment function
				res = num;
				increment(&num);
				printf("res = num++\nres = %d\t num = %d\n", res, num);
				break;
			default :
				printf("Invalid choice\n");
		}
		printf("Want to continue...[Yy || Nn] : ");
		scanf("\n%c", &option);
	}while (option == 'Y' || option == 'y');
	return 0;
}
//Defining post increment function
void increment(int *p)
{
	int mask = 1;
	for (; mask; mask <<= 1)
	{
		if (*p & mask)
		{
			*p = *p ^ mask;
		}
		else
		{
			*p = *p ^ mask;
			break;
		}
	}
	return;
}
