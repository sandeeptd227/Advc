/* 
Title       : 32_float_array.c 
Author      : Sandeep
Date        : 9 July 2019
Description : Sorting a float array without copying it into another array
Input       : Float array
output      : Printing elements in array after sorting  
 */

#include <stdio.h>
#include <stdlib.h>

//Declaring the functions
void populate(float *, int);
void sorting(float **, int);
//Starting main
int main()
{
	//Declaring the variables
	int num, status, i;
	char option;
	do
	{
		//Clear the screen
		system("clear");
		//Enter the number of elements in array and store it in the variable
		printf("Enter the number of elements in the array : ");
		status = scanf("%d", &num);
		//Validating number of elements
		if (status != 1)
		{
			printf("Invalid input\n");
			return 0;
		}
		//Declaring the array
		float array[num];
		float **ptr = calloc(num, sizeof(float *));
		printf("Enter the float values in array\n");
		//Calling populate function to store values in the array
		populate(array, num);
		//Sending the adresses of each element to other addresses
		for(i = 0; i < num; i++)
		{
			ptr[i] = NULL;
		}
		//Copying addresses of each element 
		for(i = 0; i < num; i++)
		{
			ptr[i] = array + i;
		}
		//Calling the sorting function
		//Here we are sorting the addresses according to ascending order of elements 
		sorting(ptr, num);
		//Original array of elements
		printf("\nOriginal array\n");
		for (i = 0; i < num; i++)
		{
			printf("%f\n", array[i]);
		}
		//Printing the output
		printf("\nAfter sorting\n");
		for (i = 0; i < num; i++)
		{
			printf("%f\n", *(*(ptr + i)));
		}
		printf("\nWant to continue...[Yy || Nn] : ");
		scanf("\n%c", &option);
	}while (option == 'Y' || option == 'y');
	return 0;
}
//Defining the populate function
void populate(float *ptr, int num)
{
	int i;
	for (i = 0; i < num; i++)
	{
		scanf("%f", ptr++);
	}
}
//Defining the sorting function
void sorting(float **ptr, int num)
{
	float *temp;
	int i, j;
	for(i = 1; i < num; i++)
	{
		for(j = 0; j < num - 1; j++)
		{
			if ( *(*(ptr + j)) > *(*(ptr + j + 1)))
			{
				//Swapping the addresses
				temp = *(ptr + j);
				*(ptr + j) = *(ptr + j + 1);
				*(ptr + j + 1) = temp;
			}
		}
	}
}
