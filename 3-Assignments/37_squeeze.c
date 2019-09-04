/* 
Title       : 37_squeeze.c 
Author      : Sandeep
Date        : 23 June 2019
Description : Erasing the characters present in One string which are matched in another string
Input       : Two strings
output      : Squeezed string  
 */

#include <stdio.h>
#include <stdlib.h>

//Declaring functions
void xsqueeze (char *, char *);
//Starting main function
int main()
{

	//Declaring the variables 
	char option;
	int n;
	char string1[n], string2[n];
	do
	{
		//Clear the screen
		system("clear");
		//Enter the strings and store in the variables
		printf("Enter string1 : ");
		scanf("%[^\n]s", string1);
		getchar();
		printf("Enter string2 : ");
		scanf("%[^\n]s", string2);
		getchar();
		//Calling squeeze function
		xsqueeze(string1, string2);
		printf("After squeeze operation\n%s\n", string1);
		printf("Want to continue...[Yy || Nn] : ");
		scanf("\n%c", &option);
		getchar();
	}while (option == 'Y' || option == 'y');
	return 0;
}
//Defining squeeze function
void xsqueeze (char *a, char *b)
{
	int i, j, k = 0;
	for(i = 0; a[i] != '\0'; ++i)
	{
		for (j = 0; (a[i] != b[j]) && b[j] != '\0'; ++j);
			if (b[j] == '\0')
				a[k++] = a[i];
	}
	a[k] = '\0';
}
