/* 
Title       : 2_fibonacci.c 
Author      : Sandeep
Date        : 29 May 2019
Description : Print the fibonacci series upto given limit
Input       : No input 
output      : Fibonacci series  
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	//clear the screen
	system("clear");
	//declaring the variables 
	int limit, sum, num, res, status, abssum;
	char option;
	do
	{
		sum = 0;
		num = 1;

		//enter the limit and store it in the variable and validating if it is a number or not
		printf("enter the limit : ");
		status = scanf("%d", &limit);
		if (status != 1)
		{
			printf("invalid input\n");
			exit(1);
		}

		if (limit >= 0)
		{
			//if the limit is positive then printing positive fibonacci series
			while (sum <= limit)
			{
				printf("%d\n", sum);
				res = sum + num;
				sum = num;
				num = res;
			} 
		}
		else
		{
			//if the limit is negative then printing negative fibonacci series
			limit *= -1;
			abssum = sum;
			while (abssum <= limit )
			{
				printf("%d\n", sum);
				res = sum - num;
				sum = num;
				if (sum < 0)
				{
					abssum = sum * -1;
				}
				else
				{
					abssum = sum;
				}
				num = res;
			} 
		}
		printf("want to continue...[Yy || Nn] : ");
		scanf("\n%c", &option);
	} while (option == 'Y' || option == 'y');
	return 0;
}
