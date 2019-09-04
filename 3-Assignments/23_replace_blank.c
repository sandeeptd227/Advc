/* 
Title       : 23_replace_blank.c 
Author      : Sandeep
Date        : 9 July 2019
Description : Enter a string with multiple spaces and replace the multiple spaces with a single space
Input       : Any string
output      : String with single space in between words  
 */

#include <stdio.h>
#include <stdlib.h>
//Starting main
int main()
{
	//Declaring the variables 
	char option;
	do
	{
		//Clear the screen
		system("clear");
		int c, last_c = 0;
		//Enter a string until we type a new line
		while((c = getchar()) != '\n')
		{
			if (c == ' ')
			{
				//Checking if the last character is also a space character
				if(last_c != ' ')
				{
					putchar(c);
				}
			}
			else
				putchar(c);
				last_c = c;
		}
		printf("\nWant to continue...[Yy || Nn] : ");
		scanf("\n%c", &option);
	}while (option == 'Y' || option == 'y');
	return 0;
}

