/* 
Title       : 27_float_binary.c 
Author      : Sandeep
Date        : 27 June 2019 
Description : Printing binary form of float and double numbers 
Input       : Any number
output      : Binary form of a given number
 */

#include <stdio.h>
#include <stdlib.h>

//Declaring the functions
void floatbits(int *);
void doublebits(long int *);

//Starting main function
int main()
{

	//Declaring the variables 
	char option;
	float num;
	int choice;
	double num1;
	do
	{
		//Clear the screen
		system("clear");
		//Enter the choice and store it in the variable
		printf("Select any option\n1.Float to binary\n2.Double to binary\n");
		scanf("%d", &choice);
		//Switch case for the two operations
		switch (choice)
		{
			case 1:
				//Prompt + read a float number
				printf("Enter any float number : ");
				scanf("%f", &num);
				printf("SIGN\tEXPONENT\tMANTISSA\n");
				//Calling float to binary function
				floatbits((int *)&num);
				break;
			case 2:
				//Prompt + read a double number
				printf("Enter any double number : ");
				scanf("%lf", &num1);
				printf("SIGN\tEXPONENT\tMANTISSA\n");
				//Calling double to binary function
				doublebits((long int *)&num1);
				break;
			default:
				printf("Invalid choice\n");
		}
		printf("Want to continue...[Yy || Nn] : ");
		scanf("\n%c", &option);
	}while (option == 'Y' || option == 'y');
	return 0;
}
//Defining the float print bits function
void floatbits(int *ptr)
{
	//Finding the mask
	unsigned int mask = 1 << (sizeof(float) << 3) - 1;
	int count = 0;
	for(; mask; mask >>= 1)
	{
		//Finding the bits
		if(count == 1 || count == 9)
		{
			printf("\t");
		}
		*ptr & mask ? putchar('1'):putchar('0');
		count++;
	}
	putchar('\n');
}
//Defining the Doubleprint bits function
void doublebits(long int *ptr)
{
	//Finding the mask
	unsigned long int mask = 1UL << (sizeof(double) << 3) - 1;
	int count = 0;
	for(; mask; mask >>= 1)
	{
		//Finding the bits
		if(count == 1 || count == 12)
		{
			printf("\t");
		}
		*ptr & mask ? putchar('1'):putchar('0');
		count++;
	}
	putchar('\n');
}
