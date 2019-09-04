/* 
Title       : 46_transpose.c 
Author      : Sandeep
Date        : 5 July 2019
Description : Finding the transpose of the given matrix and product of the given array with its transpose
Input       : No of rows , columns and elements of the array
output      : Printing transpose of given array and matrix after multiplication  
 */

#include <stdio.h>
#include <stdlib.h>
//Declaring the functions
void populate(int **array, int rows, int cols);
void printarray(int **array, int rows, int cols);
void transpose_array(int **array, int **transpose, int rows, int cols);
void multiplication( int **array, int **transpose, int **multiply, int rows, int cols);
//Starting main function
int main()
{

	//Declaring the variables 
	char option;
	int **array, **transpose, **multiply, i, rows, cols;
	do
	{
		//Clear the screen
		system("clear");
		//Enter the number and store it in the variable
		printf("Enter number of rows and columns : ");
		scanf("%d%d", &rows, &cols);
		//Allocating memory for input array
		//Allocate a one dimensional array of int pointers
		array = (int **)malloc(rows * sizeof(int *));
		//Allocate a one dimensional array of integers for each row
		for(i = 0; i < rows; i++)
		{
			array[i] = (int *)malloc(cols * sizeof(int));
		}
		//Allocating memory for transposed array
		//Allocate a one dimensional array of int pointers
		transpose = (int **)malloc(cols * sizeof(int *));
		//Allocate a one dimensional array of integers for each row
		for(i = 0; i < cols; i++)
		{
			transpose[i] = (int *)malloc(rows * sizeof(int));
		}
		//Allocating the memory for product of two array
		//Allocate a one dimensional array of int pointers
		multiply = (int **)malloc(rows * sizeof(int *));
		//Allocate a one dimensional array of integers for each row
		for(i = 0; i < rows; i++)
		{
			multiply[i] = (int *)malloc(rows * sizeof(int));
		}
		//Populating the input array
		populate(array, rows, cols);
		printf("Input array\n");
		printarray(array, rows, cols);
		//Calling transpose function to find transpose of input array
		transpose_array(array, transpose, rows, cols);
		printf("Transpose of the given array\n");
		printarray(transpose, cols, rows);
		//Calling multiplication function
		multiplication(array, transpose, multiply, rows, cols);
		printf("After mutliplication\n");
		printarray(multiply, rows, rows);
		printf("Want to continue...[Yy || Nn] : ");
		scanf("\n%c", &option);
	}while (option == 'Y' || option == 'y');
	return 0;
}
//Defining the populate function
void populate(int **array, int rows, int cols)
{
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for(j = 0; j < cols; j++)
		{
			printf("Enter array[%d][%d] : ", i, j);
			scanf("%d", (*(array + i) + j));
		}
	}
}
//Defining the printarray function
void printarray(int **array, int rows, int cols)
{
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for(j = 0; j < cols; j++)
		{
			printf("%d\t", *(*(array + i) + j));
		}
		printf("\n");
	}
}
//Defining the transpose_array function
void transpose_array(int **array, int **transpose, int rows, int cols)
{
	int i, j, temp;
	for (i = 0; i < rows; i++)
	{
		for(j = 0; j < cols; j++)
		{
			*(*(transpose +j) + i) = *(*(array + i) + j);
		}
	}
}
//Defining the multiplication function
void multiplication( int **array, int **transpose, int **multiply, int rows, int cols)
{
	int i, j, k;
	for(i = 0; i < rows; i++)
	{
		for(j = 0; j < rows; j++)
		{
			*(*(multiply + i) + j) = 0;
			for(k = 0; k < cols; k++)
			{
				*(*(multiply + i) + j) += *(*(array + i) + k) * *(*(transpose + k) + j);
			}
		}
	}
}
