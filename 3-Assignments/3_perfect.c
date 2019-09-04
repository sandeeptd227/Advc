/* 
Title       : 3_perfect.c 
Author      : Sandeep
Date        : 29 May 2019
Description : Checking whether the given number is perfect or not
Input       : Any number
output      : Perfect number or not  
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	//clear the screen
	system("clear");
	//declaring the variables 
	int num, status, sum, i;
	char option;
	do
	{
		sum = 1;
		//enter the number and store it in the variable and validating
		printf("enter any number : ");
		status = scanf("%d", &num);
		if (status != 1 || num <= 0)
		{
			printf("invalid input\n");
			exit(1);
		}

		//finding the factors of a number and adding them
		for (i = 2; i <= num; i++)
		{
			if (num % i == 0)
			{
				sum = sum + i;
			}
		}
		//if sum of factors is double the number we have given then it is a perfect number
		if ( num * 2 == sum)
		{
			printf("PERFECT NUMBER\n");
		}
		else
		{
			printf("NOT A PERFECT NUMBER\n");
		}
		printf("want to continue...[Yy || Nn] : ");
		scanf("\n%c", &option);
	}while (option == 'Y' || option == 'y');
	return 0;
}

