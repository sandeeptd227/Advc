/* 
Title       : 36_stringreverse.c 
Author      : Sandeep
Date        : 23 June 2019
Description : Printing the revserse of the given string using recurssion
Input       : Any string
output      : Reverse of the given string  
 */

#include <stdio.h>
#include <stdlib.h>

//Declaring the functions
size_t my_strlen (const char *);
void reverse(char *, int, int);

//Starting main function
int main()
{

	//Declaring the variables 
	char option;
	int n;
	char a[n];
	do
	{
		//Clear the screen
		system("clear");
		//Enter the string and store it in the variable
		printf("Enter any string\n");
		scanf("%s", a);
		size_t len = my_strlen(a);
		//Calling reverse function
		reverse(a, 0, len-1);
		printf("After reversing\n%s\n", a);
		printf("Want to continue...[Yy || Nn] : ");
		scanf("\n%c", &option);
	}while (option == 'Y' || option == 'y');
	return 0;
}

//Function to find string length
size_t my_strlen (const char *s)
{
	int count = 0;
	while (*s)
	{
		count++;
		s++;
	}
	return count;
}
//Defining reverse function
void reverse(char *s, int start, int end)
{
	char temp;
	if (start >= end)
		return;
	temp = *(s + start);
	*(s + start) = *(s + end);
	*(s + end) = temp;
	reverse(s, ++start, --end);
}
