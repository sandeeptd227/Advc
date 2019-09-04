/* 
Title       : 15_bitwise_lsb.c
Author      : Sandeep
Date        : 9 June 2019
Description : Replacing 'n' bits from a position of a value by 'n' lsbs of number 
Input       : A number, value, position(b) and 'a' value to get the number of bits 
output      : Printing Value replaced with 'n' ls bits of number at position 'b' of value 
 */

#include <stdio.h>
#include <stdlib.h>

//declaring functions
unsigned int replacing(unsigned int, unsigned int, short, short);
void conversion(unsigned int);

//starting main function
int main()
{

	//declaring the variables 
	char option;
	unsigned int num, val, res;
	short b, a, status, bits;
	do
	{
		//clear the screen
		system("clear");

		//enter the number and store it in the variable
		printf("enter number, value, a and b : ");
		status = scanf("%d%d%hi%hi", &num,&val,&a,&b);

		//validating the input
		if (status != 4 || a <= 0 || a >= b || b > 31 )
		{
			printf("invalid input\n");
			return 0;
		}
		bits = b - a + 1;
		printf("num = ");
		conversion(num);
		printf("val = ");
		conversion(val);
		res = replacing(num, val, bits, b);   /*function call */
		printf("res = ");
		conversion(res);
		printf("result is %d\n", res);

		printf("want to continue...[Yy || Nn] : ");
		scanf("\n%c", &option);
	}while (option == 'Y' || option == 'y');
	return 0;
}

//defining function
unsigned int replacing(unsigned int num, unsigned int val, short bits, short b)
{
	//clearing b-a+1 bits at b position in value and replacing with b-a+1 lsb's from number
	val = val & ~(~((~0 << bits)) << b - bits + 1) | (num & ~(~0 << bits)) << b - bits + 1;
	return val;
}

//function for converting decimal to binary
void conversion(unsigned int num)
{
	unsigned int mask;
	mask = 1 << (sizeof(unsigned int) << 3) - 1;
	for (; mask; mask >>= 1)
	{
		num & mask ? putchar('1') : putchar('0');
	}
	printf("\n");
}
