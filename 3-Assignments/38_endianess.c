/* 
Title       : 38_endianess.c 
Author      : Sandeep
Date        : 11 July 2019
Description : Checking the endianess of the machine
Input       : No input
output      : Little endian/Big endian
 */

#include <stdio.h>
#include <stdlib.h>
//Declaring functions
int endianess(unsigned int *pos, char ch);

int main()
{

	//Declaring the variables 
	char option;
	do
	{
		//Clear the screen
		system("clear");
		unsigned int num = 0x1A2B3C4D;
		char *ch = (char *)&num;
		//Calling endianess function
		if(endianess(&num, *ch))
			printf("Little endian\n");
		else
			printf("Big endian\n");
		printf("Want to continue...[Yy || Nn] : ");
		scanf("\n%c", &option);
	}while (option == 'Y' || option == 'y');
	return 0;
}
//Defining the endianess function
int endianess(unsigned int *pos, char ch)
{
	if (ch == *(char *)pos)
	{
		printf("Number : %X\n", ch);
		return 1;
	}
	return 0;
}
