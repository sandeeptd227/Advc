/*
Title       : Sevensegmentdisplay
Author      : Sandeep
Date        : 6 June 2019
Description : Printing the even numbers in 0 to 9 in seven segment display
Input       : Any even number between 0 and 9, Number of columns in between 10 and 20, Character to print
Output      : Seven segment display
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	//clear screen
	system("clear");

	//declare variables
	int num, columns, rows, pattern, status1, status2, count = 0, i, j, total;
	float average;
	char ch;

	//prompt + read the number
	printf("enter the number  : ");
	status1 = scanf("%d", &num);

	//validating number
	if (status1 != 1 || num % 2 != 0 || num <= 0 || num > 9)
	{
		printf("invalid input");
		exit(1);

	}
	// prompt + read the colunms
	printf("enter the columns : ");
	status2 = scanf("%d", &columns);

	// validating the columns
	if (status2 != 1 || columns < 10 || columns > 20)
	{
		printf("invalid columns");
		exit(2);
	}

	//prompt + read the character
	printf("enter the character : ");
	scanf("\n%c", &ch);

	//validating the character
	if ( !(ch == '*' || ch == '@' || ch == '#' || ch == '$')) 
	{
		printf("invalid character input\n");
		exit(3);
	}
	rows = 2 * columns + 1;
	for (i = 1; i <= rows; i++)
	{
		//finding the type of pattern for the particular row if the number is 2
		if (num == 2)
		{
			if (i == 1 || i == columns + 1 || i == rows)
			{
				pattern = 1;
			}
			else if (i > 1 && i < columns + 1)
			{
				pattern = 2;
			}
			else
			{
				pattern = 3;
			}
		}
		//finding the type of pattern for the particular row if the number is 6
		else if (num == 6)
		{
			if (i == 1 || i == columns + 1 || i == rows)
			{
				pattern = 1;
			}
			else if (i > 1 && i < columns + 1)
			{
				pattern = 3;
			}
			else
			{
				pattern = 4;
			}
		}
		//finding the type of pattern for the particular row if the number is 4
		else if (num == 4)
		{
			if (i > columns + 1)
			{
				pattern = 2;
			}
			else if (i >= 1 && i < columns + 1)
			{
				pattern = 4;
			}
			else
			{
				pattern = 1;
			}
		}
		//finding the type of pattern for the particular row if the number is 8
		else 
		{
			if (i == 1 || i == columns + 1 || i == rows)
			{
				pattern = 1;
			}
			else
			{
				pattern = 4;
			}
		}
		// writing switch case for the required patterns
		switch (pattern)
		{
			//logic for the pattern  "**********"
			case 1 : for(j = 1; j <= columns ; j++)
					 {
						 printf("%c", ch);
						 count++;
					 }
					 break;
					 //logic for the pattern  "----------*"
			case 2 : for(j = 1; j <= columns ; j++)
					 {
						 if (j != columns)
						 {
							 printf(" ");
						 }
						 else
						 {
							 printf("%c", ch);
							 count++;
						 }
					 }
					 break;
					 //logic for the pattern "*----------"
			case 3 : for(j = 1; j <= columns ; j++)
					 {
						 if (j != 1)
						 {
							 printf(" ");
						 }
						 else
						 {
							 printf("%c", ch);
							 count++;
						 }
					 }
					 break;
					 //logic for the pattern "*---------*"
			case 4 : for(j = 1; j <= columns ; j++)
					 {
						 if (j == 1 || j == columns)
						 {
							 printf("%c", ch);
							 count++;
						 }
						 else
						 {
							 printf(" ");
						 }
					 }
					 break;
			default : printf("invalid");
		}
		printf("\n");
	}
	total = rows * columns;
	average = (float)count / total;
	printf("average = %f\n", average);
	return 0;
}
