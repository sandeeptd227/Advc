/* 
Title       : 14_bitwise_lib.c 
Author      : Sandeep
Date        : 9 June 2019
Description : Executing all the bitwise operations for getting, replacing, toggling and printing bits 
Input       : A Number, A value, Number of bits and Position
output      : Printing result based on selection of type of function  
 */

#include <stdio.h>
#include <stdlib.h>

//declaring functions
unsigned char get_n_bits(unsigned char, short);
unsigned char replace_n_bits(unsigned char, short, unsigned char);
unsigned char get_n_bits_position(unsigned char, short, unsigned char);
unsigned char replace_n_bits_position(unsigned char, short, unsigned char, unsigned char);
unsigned char toggle_bits_position(unsigned char, short, unsigned char);
unsigned char print_bits(unsigned char, short);
void binary(unsigned char);

//start main fucntion
int main()
{

	//declaring the variables 
	char option;
	short bits, status, input;
	unsigned char num, res, val, pos, mask;
	do
	{
		//clear the screen
		system("clear");
		//enter the number,number of bits and store it in the variables
		printf("enter the number, number of bits : ");
		status = scanf("%hhd%hi", &num, &bits);

		//validating the input
		if (status != 2 || bits < 1 || bits > 8)
		{
			printf("invalid input\n");
			return 0;
		}

		//selecting the option
		printf("\nSelect an option\n1.get_n_bits\n2.replace_n_bits\n3.get_n_bits_from_position\n4.replace_n_bits_from_position\n5.toggle_n_bits_from_position\n6.print_bits\n\n");
		scanf("%hi", &input);
		printf("num = ");
		binary(num);
		//switch case for required option
		switch (input)
		{
			//calling functions
			case 1:
				//calling get_n_bits function
				res = get_n_bits(num,bits); /*function call*/
				printf("result : %hhd\n", res);
				binary(res);
				break;
			case 2: 
				printf("enter value : ");
				scanf("%hhd", &val);
				printf("val = ");
				binary(val);
				//calling replace_n_bits function
				res = replace_n_bits(num,bits,val); /*function call*/
				printf("result : %hhd\n", res);
				binary(res);
				break;
			case 3:
				printf("enter position : ");
				scanf("%hhd", &pos);
				//calling get_n_bits_position function
				res = get_n_bits_position(num,bits,pos);  /*function call */
				printf("result : %hhd\n", res);
				binary(res);
				break;
			case 4:	
				printf("enter position and value : ");
				scanf("%hhd%hhd", &pos, &val);
				printf("val = ");
				binary(val);
				//calling replace_n_bits_position function
				res = replace_n_bits_position(num,bits,pos,val);  /*function call*/
				printf("result : %hhd\n", res);
				binary(res);
				break;
			case 5:
				printf("enter position : ");
				scanf("%hhd", &pos);
				//calling toggle_n_bits_position function
				res = toggle_bits_position(num,bits,pos);  /*function call */
				printf("result : %hhd\n", res);
				binary(res);
				break;
			case 6:
				//calling print_bits function
				res = print_bits(num,bits);  /*function call */
				printf("result : %hhd\n", res);
				binary(res);
				break;
			default : 
				printf("invalid choice\n");
		}
		printf("want to continue...[Yy || Nn] : ");
		scanf("\n%c", &option);
	}while (option == 'Y' || option == 'y');
	return 0;
}

//defining function for get_n_bits 
unsigned char get_n_bits(unsigned char num, short bits)
{
	return num & ~(~0 << bits);
}

//defining function for replace_n_bits
unsigned char replace_n_bits(unsigned char num, short bits, unsigned char val)
{
	return (num & (~0 << bits)) | (val & ~(~0 << bits));
}

//defining function for get_n_bits_position
unsigned char get_n_bits_position(unsigned char num, short bits, unsigned char pos)
{
	return (num & ~(~0 << bits) << pos - bits + 1) >> pos - bits + 1;
}

//defining function for replace_n_bits_position from a value
unsigned char replace_n_bits_position(unsigned char num, short bits, unsigned char pos, unsigned char val)
{
	return (num & ~(~(~0 << bits) << pos - bits + 1)) | (val & ~(~0 << bits)) << pos - bits + 1;
}

//defining function for toggle_n_bits_position
unsigned char toggle_bits_position(unsigned char num, short bits, unsigned char pos)
{
	return num ^ ~((~0 << bits)) << pos - bits + 1;
}

//defining function for print_n_bits 
unsigned char print_bits(unsigned char num, short bits)
{
	return num & ~(~0 << bits);
}
void binary(unsigned char num)
{
	unsigned char mask = 1 << (sizeof(unsigned char) << 3)-1;
	for (; mask; mask >>= 1)
	{
		num & mask ? putchar('1') : putchar('0');
	}
	printf("\n");
}
