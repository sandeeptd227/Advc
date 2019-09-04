/* 
Title       : 12_print_bits.c 
Author      : Sandeep
Date        : 4 June 2019
Description : Printing binary for the given decimal number
Input       : Any number
output      : Binary form of given number  
 */

#include <stdio.h>
#include <stdlib.h>

//declaring function
void binary(unsigned int);

//starting main
int main()
{
	//clear the screen
	system("clear");

	//declaring the variables 
	unsigned int num, num1, status;
	char option;
	do
	{
		//enter the number and store it in the variable
		printf("enter a number : ");
		status = scanf("%d", &num);

		//validating the given input
		if (!status)
		{
			printf("invalid input\n");
			return 0;
		}

		num1 = num * -1;

		// printing binary form of given number
		printf("%d : ", num);
		binary(num);      /*function call*/
		// printing binary form of negative of given number
		printf("%d : ", num1);    /*function call*/
		binary(num1);

		printf("want to continue...[Yy || Nn] : ");
		scanf("\n%c", &option);
	}while (option == 'Y' || option == 'y');
	return 0;
}

//defining function for coverting decimal to binary
void binary(unsigned int num)
{
	unsigned int mask = 1 << (sizeof(unsigned int) << 3) -1;
	for (; mask; mask >>= 1)
	{
		num & mask ? putchar('1'):putchar('0');
	}
	printf("\n");
}
