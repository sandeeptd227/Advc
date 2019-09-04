/* 
Title       : 19_recursive_main.c 
Author      : Sandeep
Date        : 12 June 2019
Description : Printing the factorial using recursion. Here the recursive function will be the main function itself
Input       : Any number
output      : Factorial of the given number  
 */

#include <stdio.h>
#include <stdlib.h>
int main()
{ 
	char option;
	do 
	{
		//Declare variables
		static int num, fact = 1;
		int status;
		if (fact <= 1)
		{
			//Enter the input only once
			printf("Enter the number : ");
			status = scanf("%d", &num);
			//Validating input
			if (status != 1)
			{
				printf("Invalid input\n");
				return 0;
			}
		}
		if(num > 0)
		{
			fact *= num;
			num--;
			//Calling the main function again
			main();
			return fact;
		}
		printf("Factorial is %d\n", fact);
		fact = 1;
		printf("Want to continue ...[Yy / Nn] :");
		scanf("\n%c", &option);
	}while (option == 'Y' || option == 'y');
	return 0;
}
