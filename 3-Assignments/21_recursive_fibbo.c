/* 
Title       :  
Author      : Sandeep
Date        : 12 June 2019
Description : Print the fibonacci series upto given limit using recurssion 
Input       : Limit  
output      : Positive and Ngeative Fibonacci series  
 */

#include <stdio.h>
#include <stdlib.h>

//declare the function
void pos_fib(int, int, int);
void neg_fib(int, int, int);

int main()
{
	//clear the screen
	system("clear");
	//declaring the variables 
	int limit, sum, num, status;
	char option;
	do
	{
		sum = 0;
		num = 1;

		//enter the limit and store it in the variable and validating if it is a number or not
		printf("enter the limit : ");
		status = scanf("%d", &limit);
		//validating the input
		if (status != 1)
		{
			printf("invalid input\n");
			return 0;
		}
		if (limit > 0)
		{
			//calling positive fibonacci series if the limit is positive
			pos_fib(sum, num, limit);
		}
		else
		{
			//calling negative fibonacci series if the limit is negative
			limit *= -1;
			neg_fib(sum, num, limit);
		}
		printf("want to continue...[Yy || Nn] : ");
		scanf("\n%c", &option);
	} while (option == 'Y' || option == 'y');
	return 0;
}
//defining the positive fibonacci series function
void pos_fib( int sum, int num, int limit)
{
	if (sum <= limit)
	{
		printf("%d\n",sum);
		pos_fib(num, sum + num, limit);
	}
}
//defining the negative fibonacci series function
void neg_fib(int sum, int num, int limit)
{
	int 	abssum;
	if (sum < 0)
	{
		abssum = sum * -1;
	}
	else
	{
		abssum = sum;
	}
	if(abssum <= limit )
	{
		printf("%d\n", sum);
		neg_fib(num, sum - num, limit);
	} 
}

