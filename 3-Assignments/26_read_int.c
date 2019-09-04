/* 
Title       : 26_read_int.c 
Author      : Sandeep
Date        : 10 July 2019
Description : Reading numbers as a character by character and printing it as a number
Input       : Any numbers from 0 to 9
output      : Combining the Entered numbers and printing them as a single number  
 */

#include <stdio.h>
#include <stdlib.h>
//Declaring functions
int read_int(int *num);
//Starting main
int main()
{

	//Declaring the variables 
	char option;
	char c;
	do
	{
		//Clear the screen
		system("clear");
		int num = 0, count = 0;
		//Calling the function for converting characters to integers
		read_int(&num);
		//Printing the output
		printf("NUMBER = %d\n", num);
		printf("Want to continue...[Yy || Nn] : ");
		scanf("\n%c", &option);
		getchar();
	}while (option == 'Y' || option == 'y');
	return 0;
}
//Declaring read_int function
int read_int(int *num)
{
	char c;
	int count = 0;
	//Taking the input until new line character is encountered
	while((c = getchar()) != '\n')
	{
		if((c >= '0' && c <= '9') || c == '-' || c == '+')
		{
			if (c == '-')
			{
				count = 1;
				continue;
			}
			if (c == '+')
				continue;
			//Converting ascii to int 
			*num = *num * 10 + c - '0';
		}
		else
		{
			printf("Invalid input. Enter numbers between 0 and 9\n");
			return;
		}
	}
	if(count == 1)
		*num *= -1;
}
