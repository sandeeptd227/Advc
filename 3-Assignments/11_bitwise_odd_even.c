/* 
Title       : 11_bitwise_odd_even.c
Author      : Sandeep
Date        : 4 June 2019
Description : Printing whether the given number is even or odd using bitwise
Input       : Any number
output      : Even or odd  
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	//clear the screen
	system("clear");

	//declaring the variables 
	int num, status;
	char option;
	do
	{
		//enter the number and store it in the variable
		printf("enter a number : ");
		status = scanf("%d", &num);

		//validating the input
		if (!status || num == 0)
		{
			printf("invalid input");
			exit(1);
		}

		//checking the last bit of the given number
		if(num & 1) 
		{
			printf("odd\n");
		}
		else
		{
			printf("even\n");
		}
		printf("want to continue...[Yy || Nn] : ");
		scanf("\n%c", &option);
	}while (option == 'Y' || option == 'y');
	return 0;
}
