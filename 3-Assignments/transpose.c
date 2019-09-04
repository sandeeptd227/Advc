/* 
Title       : 
Author      : Sandeep
Date        : 
Description :
Input       : 
output      :   
 */

#include <stdio.h>
#include <stdlib.h>

//void populate(int *array[], int row, int col);
void populate(int *array, int row, int col);
void printarray(int *array, int row, int col);
void transpose(int *array1, int *array2, int row, int col);
int main()
{

	//Declaring the variables 
	char option;
	int row, col, status;
	do
	{
		//Clear the screen
		system("clear");
		//Prompt + read the number of rows and columns
		printf("Enter number of rows and columns : ");
		status = scanf("%d%d", &row, &col);
		//Validating the input
		if (status != 2)
		{
			printf("Invalid input\n");
			return 0;
		}
		//Declaring two arrays
		//int array1[row][col], array2[col][row];
		int *array1 = calloc(row * col , sizeof(int));
		int *array2 = calloc(row * col , sizeof(int));
		//Populate array1 by calling populate function
		printf("Enter elements in the array\n");
		//int (*ptr)[col] = array1;
		populate(array1, row, col);
		printf("Input array\n");
		printarray(array1, row, col);
		//Calling tranpose function
	transpose(array1, array2, row, col);
	printarray(array2, col, row);

		//Logic
		printf("Want to continue...[Yy || Nn] : ");
		scanf("\n%c", &option);
	}while (option == 'Y' || option == 'y');
	return 0;
}
void populate(int *array, int row, int col)
{
	int i, j;
	for(i = 0; i < row * col; i++)
	{
			scanf("%d", array + i);
		}
}

void printarray(int *array, int row, int col)
{
	int i, j;
	for(i = 0, j = 0; i < row * col; i++, j++)
	{
			printf("%d\t", *(array + i));
			if((i+1) % col == 0)
		printf("\n");
	}
}
#if 1
void transpose(int *array1, int *array2, int row, int col)
{
	int i, j;
	for (i = 0, j = row * col - 1; i < row * col; ++i, --j)
	{

*(array2 + j) = *(array1  + i);
		}
	}

#endif
