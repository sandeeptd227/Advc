/* 
Title       : 17_swap.c 
Author      : Sandeep
Date        : 17 june 2019
Description : swapping two numbers using bitwise operators and functions
Input       : Two numbers
output      : Two numbers after swapping
 */

#include <stdio.h>
#include <stdlib.h>

//declaring function
void swap(int *, int *);

int main()
{

	//declaring the variables 
	char option;
	int num1, num2;
	do
	{
		//clear the screen
		system("clear");
		//enter the numbers and store it in the variables
		printf("enter two numbers : ");
		scanf("%d%d", &num1, &num2);
		printf("before swapping\nnum = %d\tres = %d\n", num1, num2);
		//calling function for swapping
		swap(&num1, &num2);
		printf("after swapping\nnum = %d\tres = %d\n", num1, num2);

		printf("want to continue...[Yy || Nn] : ");
		scanf("\n%c", &option);
	}while (option == 'Y' || option == 'y');
	return 0;
}
//defining swapping function
void swap(int *p1, int *p2)
{
	*p1 = *p1 ^ *p2;
	*p2 = *p1 ^ *p2;
	*p1 = *p1 ^ *p2;
}

