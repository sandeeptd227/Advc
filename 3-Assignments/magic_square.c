/* 
Title       : 28_magic_square.c 
Author      : Sandeep
Date        : 7 July 2019
Description : Executing 3 * 3 magic square
Input       : No input
output      : Printing 3 * 3 magic square
 */

#include <stdio.h>
#include <stdlib.h>
//Declaring functions
void magic_square(int **array, int rows);
void initialize(int **array, int rows);
void printarray(int **array, int rows);
//Starting main
int main()
{

	//Declaring the variables 
	char option;
	int **array, rows, i;
	do
	{
		//Clear the screen
		system("clear");
		//Enter the order of matrix
		printf("Enter the rows :");
		scanf("%d", &rows);
		//Validating the input
		if (rows % 2 == 0)
		{
			printf("Rows are not odd\n");
			return 0;
		}
		//Allocating memory for array dynamically
		array = (int **)malloc(rows * sizeof(int *));
		//Allocate a one dimensional array of integers for each row
		for(i = 0; i < rows; i++)
		{
			array[i] = (int *)malloc(rows * sizeof(int));
		}
		//Initializing the array
		initialize(array, rows);
		//Calling magic square function
		magic_square(array, rows);
		//Printing output
		printf("Magic square\n\n");
		printarray(array, rows);
		printf("Want to continue...[Yy || Nn] : ");
		scanf("\n%c", &option);
	}while (option == 'Y' || option == 'y');
	return 0;
}
//Defining magic square function
void magic_square(int **array, int rows)
{
	int num, i, j;
	i = 0;
	j = (rows - 1) / 2;
	for(num = 1; num <= (rows * rows); num++)
	{
		
		while((*(*(array + i) + j)) != 0)
		{
			//Finding the position in array if the element is already present
			if (i == rows - 1)
				i = rows - i;
			else
				i = i + 2;
			if (j == 0)
				j = rows - 1;
			else
				j = j - 1;
		}
		*(*(array + i) + j) = num;
		//Finding the position in array if the element is 0
		if(i == 0)
			i = rows - 1;
		else
			i = i - 1;
		if(j == (rows - 1))
			j = 0;
		else
			j++;
	}
}
//Initializing the array
void initialize(int **array, int rows)
{
	int i, j;
	for(i = 0; i < rows; i++)
	{
		for(j = 0; j < rows; j++)
		{
			*(*(array + i) + j) = 0;
		}
	}
}
//Defining print array function
void printarray(int **array, int rows)
{
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for(j = 0; j < rows; j++)
		{
			printf("%d\t", *(*(array + i) + j));
		}
		printf("\n");
	}
}
