/*
Title       : 8_x_format.c
Author      : Sandeep
Date        : 28 May 2019
Description : Printing 'hello' in X format using for loops
Input       : Number of rows to print 
Output      : 'hello' in X format
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	//declare the variables
	int rows, i, j, pos1, pos2, loops, columns, status, constant, halfrows;

	//enter the rows and store in the variable
	printf("enter the number of rows\n");
	scanf("%d",&rows);

	//finding number of times the loop should run in each row
	if(rows % 2)
	{
		loops = rows + 1;
	}
	else
	{
		loops = rows;
	}
	constant = loops + 1;
	status = rows % 2;
	halfrows = rows / 2 + 1;

	//logic to print 'hello' in X format
	for (i = 1; i <= rows ; i++)
	{
		if (!status)
		{
			j = loops;
			for (j = loops; j >= 1; j-- )
			{
				if (i == j || i + j == constant)
				{ 
					printf("hello");
				}
				else
				{
					printf("-"); 
				}
			}
		}
		else
		{
			pos1 = loops;
			pos2 = constant - loops;
			for (j = 1; j <= loops; j++)
			{
				if (j == pos1 || j == pos2)
				{ 
					printf("hello");
				}
				else
				{
					printf("-"); 
				}
			}
			if (i < halfrows)
			{
				loops--;
			}
			else
			{
				loops++;
			}
		}

		printf("\n");
	}
}
