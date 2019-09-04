/* 
Title       : 6_sieve.c 
Author      : Sandeep
Date        : 12 June 2019
Description : Printing the prime numbers upto given number using sieve's method
Input       : Any number
output      : Prime numbers upto given number  
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	//clear the screen
	system("clear");

	//declaring the variables 
	char option;
	int i, num, j, status, res = 2;

	//finding limit for input
	for(i = 1; i < 20; i++)
	{
		res = res * 2;
	}
	do
	{
		//enter the number and store it in the variable
		printf("enter any number : ");
		status = scanf("%d", &num);

		//validating the input
		if (status != 1 || num > res || num <= 0)
		{
			printf("invalid input\n");
			return 0;
		}

		//declaring the array
		int a[num + 1];
		//sending values in to the array
		for (i = 0; i < num + 1; i++)
		{
			a[i] = i;
		}

		//logic for sieve's method for finding the prime numbers
		for ( i = 2; i < num + 1; i++)
		{
			for(j = i + 1; j < num + 1; j++ )
			{
				if( a[j] % i == 0)
				{
					a[j] = 0;
				}
			}
		}

		//printing the prime numbers
		for (i = 2; i < num + 1; i++)
		{ 
			if( a[i] != 0)
			{
				printf("%d\n",a[i]);
			}
		}
		printf("want to continue...[Yy || Nn] : ");
		scanf("\n%c", &option);
	}while (option == 'Y' || option == 'y');
	return 0;
}
