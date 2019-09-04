/*
Title       : 47_sizeof_macro.c
Author      : Sandeep
Date        : 18 July 2019
Description : Executing "sizeof" operator using macros
Input       : No input
Output      : Printing sizes of different datatypes
 */

#include <stdio.h>
#include <stdlib.h>
//defining the macro
#define SIZEOF(a) (char*)(&a+1) - (char*)(&a)
int main()
{
	//Declaring the variables
	int a;
	float f;
	double d;
	char ch, choice;
	do
	{
		//Clearing screen
		system("clear");
		//calling the macro and printing the results
		printf("size of (a): %zu\n", SIZEOF(a));
		printf("size of (d): %zu\n", SIZEOF(d));
		printf("size of (f): %zu\n", SIZEOF(f));
		printf("size of (ch): %zu\n", SIZEOF(ch));
		printf("Do you want to continue??? [y/n] : ");
		scanf("%c", &choice);
		getchar();
	}while (choice == 'y' || choice == 'Y');
}
