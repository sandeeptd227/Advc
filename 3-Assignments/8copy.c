/*
Title       : 8_x_format.c
Author      : Sandeep
Date        : 28 May 2019
Description : Printing 'hello' in X format using for columns
Input       : Number of rows to print 
Output      : 'hello' in X format
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	//declare the variables
	int rows, i, j, pos1, pos2, columns, status, constant, halfrows;

	//enter the rows and store in the variable
	printf("enter the number of rows\n");
	scanf("%d",&rows);

	//finding number of times the loop should run in each row
	if(rows % 2)
	{
		columns = rows + 1;
	}
	else
	{
		columns = rows;
	}
	constant = columns + 1;
	status = rows % 2;
	halfrows = rows / 2 + 1;

	//logic to print 'hello' in X format
	if (!status)
	{
		for (i = 1; i <= rows ; i++)
		{
			for (j = 1; j <= columns; j++ )
			{
				if (i == j || i + j == constant)
				{ 
					printf("hello");
				}
				else
				{
					printf(" "); 
				}
			}
			printf("\n");
		}
	}
	else
	{ 
		for (i = 1; i <= rows ; i++)
		{
			pos1 = columns;
			pos2 = constant - columns;
			for (j = 1; j <= columns; j++)
			{
				if (j == pos1 || j == pos2)
				{ 
					printf("hello");
				}
				else
				{
					printf(" "); 
				}
			}
			if (i < halfrows)
			{
				columns--;
			}
			else
			{
				columns++;
			}
			printf("\n");
		}
	}	
}
