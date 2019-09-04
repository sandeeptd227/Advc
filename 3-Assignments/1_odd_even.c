/* 
Title       : 1_odd_even.c
Author      : Sandeep
Date        : 24 May 2019
Description : To check whether given number is even or odd and its sign
Input       : Any number
output      : Even or Odd and its sign  
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	//clear the screen
	system("clear");

	//declaring the variables 
	int num, res = 1, i, status;

	//enter the number and store it in the variable
	printf("enter the number : ");
	status = scanf("%d", &num);

	//finding the limits to validate given input 
	for (i = 1; i <= 20; i++)
	{
		res = res * 2;
	}

	//checking the input if it is a number and in the given limits
	if (status != 1 || ( num <= -res || num >= res))
	{
		printf("invalid input\n");
		exit(1);
	}

	//checking the number if it is negative or positve and even or odd
	if (num < 0)
	{
		if (num % 2)
		{
			printf("%d is negative and odd number\n", num);
		}
		else
		{
			printf("%d is negative and even number\n", num);
		}
	}
	else if (num > 0)
	{
		if (num % 2)
		{
			printf("%d is positive and odd number\n", num);
		}
		else
		{
			printf("%d is positive and even number\n", num);
		}
	}
	else
	{
		printf("%d is neither positive nor negative\n", num);
	}
	return 0;
}
