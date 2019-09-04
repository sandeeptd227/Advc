/* 
Title       : 4_ascii.c 
Author      : Sandeep
Date        : 29 May 2019
Description : Print the ascii values table and also show which ascii characters are non printable
Input       : No input
output      : Print ASCII table
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
	//clear the screen
	system("clear");
	//declaring the variables 
	int i;
	char option, ch;
	do
	{
		ch = 0;
		printf("Decimal\tOctal\tHexDec\tCharacter\n");
		//logic to print ascii table and also finding non printable characters using isprint()
		for (i = 0; i <= 127; i++)
		{
			if (isprint (ch))
			{
				printf("%d\t%o\t%X\t%c\n",i,i,i,ch);
			}
			else
			{
				printf("%d\t%o\t%X\tNon Printable\n",i,i,i);
			}
			ch = ch + 1;
		}
		printf("want to continue...[Yy || Nn] : ");
		scanf("\n%c", &option);
	}while (option == 'Y' || option == 'y');
	return 0;
}
