/* 
Title       : 34_sort_names.c 
Author      : Sandeep
Date        : 7 July 2019
Description : Sorting the names in alphabetical order
Input       : Any number of strings
output      : Sorted names  
 */

#include <stdio.h>
#include <stdlib.h>
//Declaring functions
void sorting(char (*)[], int);
void my_strcpy(char *str1, char *str2);
int my_strcmp(char *str1, char *str2);
//Starting main function
int main()
{

	//Declaring the variables 
	char option;
	int rows, i, status;
	do
	{
		//Clear the screen
		system("clear");
		//Enter the number of strings and store it in the variable and validating
		printf("Enter number of strings : ");
		status = scanf("%d", &rows);
		if (status != 1)
		{
			printf("Invalid input\n");
			return 0;
		}
		//Declaring array of strings
		char array[rows][50];
		//Enter the strings one by one
		printf("Enter %d strings\n", rows);
		for(i = 0; i < rows; i++)
		{
			scanf("%s", array[i]);
		}
		//Calling sorting function
		sorting(array, rows);
		//Printing the names after sorting
		printf("\nAfter sorting\n\n");
		for(i = 0; i < rows; i++)
		{
			printf("%s\n", array[i]);
		}
		printf("Want to continue...[Yy || Nn] : ");
		scanf("\n%c", &option);
	}while (option == 'Y' || option == 'y');
	return 0;
}

//Defining sorting function
void sorting(char (*array)[50], int rows)
{
	int i, j;
	char temp[50];
	for (i = 0; i < rows; i++)
	{
		for (j = i + 1; j < rows; j++)
		{
			//Comapring each string
			if (my_strcmp(*(array + i), *(array + j)) > 0)
			{
				//Swapping the strings
				my_strcpy(temp,*(array + i));
				my_strcpy(*(array + i), *(array + j));
				my_strcpy(*(array + j), temp);
			}
		}
	}
}
//Defining my_strcpy function 
void my_strcpy(char *str1, char *str2)
{
	char temp[50] = {'\0'};
	int index = 0;
	//Copying character by character
	while (*(str2 + index) != '\0')
	{
		*(str1 + index) = *(str2 + index);
		index++;
	}
	*(str1 + index) = '\0';
}
//Defining my_strcmp function
int my_strcmp(char *str1, char *str2)
{
	int i;
	for(i = 0; *(str1 + i) && *(str2 +i); i++)
	{
		//if characters are same or inverting the 6th bit makes them same
		if(*(str1 + i) == *(str2 + i) || (*(str1 + i) ^ 32) == *(str2 + i))
			continue;
		else
			break;
	}
	if (*(str1 + i) == *(str2 + i))
		return 0;
	if ((*(str1 + i )|32) < (*(str2 + i)|32))
		return -1;
	return 1;
}
