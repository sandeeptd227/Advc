/* 
Title       : 40_calc_mean 
Author      : Sandeep
Date        : 1 July 2019
Description : Calculating mean of the array 
Input       : Selecting datatype, elements in the array 
output      : Mean of the given array  
 */

#include <stdio.h>
#include <stdlib.h>

//Declaring the functions
void short_mean(const void *base, size_t elements, size_t size, const void *mean);
void int_mean(const void *base, size_t elements, size_t size, const void *mean);
void float_mean(const void *base, size_t elements, size_t size, const void *mean);
void double_mean(const void *base, size_t elements, size_t size, const void *mean);
//Starting main
int main()
{

	//Declaring the variables 
	char option;
	int elements, status, choice, i;
	float mean = 0;
	do
	{
		//Clear the screen
		system("clear");
		//Enter the number of elements in array  and store it in the variable
		printf("Enter number of elements in array : ");
		status = scanf("%d", &elements);
		//Validating input
		if (status != 1)
		{
			printf("Invalid input\n");
			return 0;
		}
		//Prompt to select data type of array + read
		printf("Select data type of the array\n1.Short Int\n2.Int\n3.Float\n4.Double\n");
		scanf("%d", &choice);
		//Declaring arrays
		int int_array[elements];
		float float_array[elements];
		short short_array[elements];
		double double_array[elements];
		//Writing switch case for different data types to find mean of the array
		switch (choice)
		{
			case 1:
				//Entering elements into the array
				printf("Enter %d elements of short datatype\n", elements);
				for(i = 0; i < elements; i++)
				{
					scanf("%hd", short_array + i);
				}
				//Calling the short_mean function to find mean
				short_mean(short_array, sizeof(short_array) / sizeof(short_array[0]), sizeof(short_array[0]), &mean);
				//Printing output
				printf("Mean : %f\n", mean);
				break;
			case 2:
				//Entering elements into the array
				printf("Enter %d elements of int datatype\n", elements);
				for(i = 0; i < elements; i++)
				{
					scanf("%d", int_array + i);
				}
				//Calling the int_mean function to find mean
				int_mean(int_array, sizeof(int_array) / sizeof(int_array[0]), sizeof(int_array[0]), &mean);
				//Printing output
				printf("Mean : %f\n", mean);
				break;
			case 3:
				//Entering elements into the array
				printf("Enter %d elements of float datatype\n", elements);
				for(i = 0; i < elements; i++)
				{
					scanf("%f", float_array + i);
				}
				//Calling the float_mean function to find mean
				float_mean(float_array, sizeof(float_array) / sizeof(float_array[0]), sizeof(float_array[0]), &mean);
				//Printing output
				printf("Mean : %f\n", mean);
				break;
			case 4:
				//Entering elements into the array
				printf("Enter %d elements of double datatype\n", elements);
				for(i = 0; i < elements; i++)
				{
					scanf("%lf", double_array + i);
				}
				//Calling the double_mean function to find mean
				double_mean(double_array, sizeof(double_array) / sizeof(double_array[0]), sizeof(double_array[0]), &mean);
				//Printing output
				printf("Mean : %f\n", mean);
				break;
			default:
				printf("Invalid choice\n");
		}

		printf("Want to continue...[Yy || Nn] : ");
		scanf("\n%c", &option);
	}while (option == 'Y' || option == 'y');
	return 0;
}
//Defining the short_mean function
void short_mean(const void *base, size_t elements, size_t size, const void *mean)
{
	int i;
	short sum = 0;
	//Finding the sum of elements in the array
	for (i = 0; i < elements; i++)
	{
		sum = sum + *(short *)(base + i * size);
	}
	*(float *)mean = (float) sum / elements;
}
//Defining the int_mean function
void int_mean(const void *base, size_t elements, size_t size, const void *mean)
{
	int i;
	int sum = 0;
	//Finding the sum of elements in the array
	for (i = 0; i < elements; i++)
	{
		sum = sum + *(int *)(base + i * size);
	}
	*(float *)mean = (float) sum / elements;
}
//Defining the float_mean function
void float_mean(const void *base, size_t elements, size_t size, const void *mean)
{
	int i;
	float sum = 0;
	//Finding the sum of elements in the array
	for (i = 0; i < elements; i++)
	{
		sum = sum + *(float *)(base + i * size);
	}
	*(float *)mean = sum / elements;
}
//Defining the double_mean function
void double_mean(const void *base, size_t elements, size_t size, const void *mean)
{
	int i;
	double sum = 0;
	//Finding the sum of elements in the array
	for (i = 0; i < elements; i++)
	{
		sum = sum + *(double *)(base + i * size);
	}
	*(float *)mean = (float)sum / elements;
}
