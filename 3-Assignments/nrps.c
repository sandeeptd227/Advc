/*
Title : 
Author : Sandeep
Date : 18 July 2019
Description : 
Input : Any number of characters between 2 and 9, length of the string
Output : Non repeated string of characters of given length
*/

#include <stdio.h>
#include <stdlib.h>
//Declaring functions
void mynrps(char *array, char *str, int chars, int len);
void populate(char *array, int num);
//Starting main function
int main()
{
	//Declare variables
	char option;
	int chars, len;
	do
	{
		//Prompt + read the number of characters 
		printf("Enter number of characters : ");
		scanf("%d", &chars);
		//Validate chars
		if (chars <= 1 || chars > 9)
		{
			printf("Number of characters should be in between 2 and 9\n");
			return 0;
		}
		printf("Enter length of the string : ");
		scanf("%d", &len);
		//Allocating memory for string and characters dynamically
		char *array = (char *)calloc(chars, 1);
		char *str = (char *)calloc(len + 1, 1);
		//Populating the array by different characters
		populate(array, chars);
		//Calling mynrps function 
		mynrps(array, str, chars, len);
		//Printing output
		printf("%s\n", str);
		printf("Do you want to continue...? [y / n] ");
		scanf("\n%c", &option);
	}while (option == 'y' || option == 'Y');
}
//Defining the populate function
void populate(char *array, int num)
{
	int i;
	for (i = 0; i < num; i++)
	{
		scanf("\n%c", array + i);
	}
}
//Defining mynrps function
void mynrps(char *array, char *str, int chars, int len)
{
	int i, j, k, val = 0;
	for (i = 0; i < len; i++)
	{
			if (i % chars == 0 && i != 0)
				val++;
			*(str + i) = *(array + ((i + val) % k));
	}
}
