/*
Title       : 50_demoted_in.c
Author      : Sandeep
Date        : 11 July 2019
Description : Printing demoted integer for a given float number
Input       : Any float number
Output      : Demoted integer
*/
#include <stdio.h>
#include <stdlib.h>
//Defining a structure using bit fields
typedef struct
{
	unsigned mantissa:23;
	unsigned exp:8;
	unsigned sign:1;
}demoted_t;
//Starting main
int main()
{
	//Declaring variables
	float f;
	int n;
	float num;
	char option;
	do
	{
	//Clearing the screen
	system("clear");
	printf("Enter a number : ");
	scanf("%f", &f);
	if(f >= 1 || f <= -1)
	{
	demoted_t *p = (demoted_t *)&f;
	n = p -> exp - 127;
	num = (p -> mantissa >> (23 - n)) | (1 << n);
	}
	else
		num = 0;
	printf("Demoted Number : %f\n", num);
	printf("Want to continue....[y | n] ? ");
	scanf("\n%c", &option);
	}while (option == 'Y' || option == 'y');
}
