/* 
Title       : 16_cir_right_left.c 
Author      : Sandeep
Date        : 9 June 2019
Description : Left/Right rotating the number by 'n' bits
Input       : A number and number of bits
output      : Result after Left/Right rotating  
 */

#include <stdio.h>
#include <stdlib.h>

//declaring functions
unsigned char right_rotate(unsigned char, short);
unsigned char left_rotate(unsigned char, short);
void binary(unsigned char);
int main()
{

	//declaring the variables 
	char option;
	unsigned char num, res;
	short bits, status, choice;
	do
	{
		//clear the screen
		system("clear");

		//enter the number and store it in the variable
		printf("enter the number and no of times to rotate : ");
		status = scanf("%hhd%hi", &num, &bits);
		printf("%d\n", status);
		//validating input
		if (status != 2 || bits < 1 || bits > 8)
		{
			printf("invalid input\n");
			return 0;
		}

		//prompt user to select the choice of right or left rotate
		printf("select an option\n1.Right rotate\n2.Left rotate\n\n");
		scanf("%hi", &choice); 
		printf("before rotating\n");
		binary(num);

		//calling functions in the switch case
		switch (choice)
		{
			case 1:
				res = right_rotate(num, bits);
				printf("after right rotating %hi times the result is %hhd\n", bits, res);
				binary(res);
				break;
			case 2:
				res = left_rotate(num, bits);
				printf("after left rotating %hi times the result is %hhd\n", bits, res);
				binary(res);
				break;
			default:
				printf("invalid choice\n");
		}

		printf("want to continue...[Yy || Nn] : ");
		scanf("\n%c", &option);
	}while (option == 'Y' || option == 'y');
	return 0;
}

//defining the function right_rotate
unsigned char right_rotate(unsigned char num, short bits)
{
	num = num >> bits | num << 8-bits;
	return num;
}

//defining the function left_rotate
unsigned char left_rotate(unsigned char num, short bits)
{
	num = num << bits | num >> 8-bits;
	return num;
}

//function for converting decimal to binary
void binary(unsigned char num)
{
	int mask = 1 << (sizeof(unsigned char) << 3) - 1;
	for(; mask; mask >>= 1)
	{
		num & mask ? putchar('1') : putchar('0');
	}
	printf("\n");
}
