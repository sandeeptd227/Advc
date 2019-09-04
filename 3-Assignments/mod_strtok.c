/* 
Title       : 
Author      : Sandeep
Date        : 
Description :
Input       : 
output      :   
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *my_strtok(char *, const char *);
int main()
{

	//Declaring the variables 
	char option;
	char string1[100], string2[10];
	char *token, *prev;;
	do
	{
		//Clear the screen
		system("clear");
		//Enter the number and store it in the variable
		printf("Enter the string : ");
		scanf("%[^\n]s", string1);
		size_t len = strlen(string1);
		printf("%zu\n", len);
		string1[len + 1] = '\0';
		string1[len + 2] = '\0';
		printf("sizeof string 1 = %zu\n", sizeof(string1)/sizeof(string1[0]));
		getchar();
		printf("Enter the delimiter : ");
		scanf("%[^\n]s", string2);
		size_t d_len = strlen(string2);
		string2[d_len + 1] = '\0';
		string2[d_len + 2] ='\0';

		//Logic
		printf("After splitting into tokens\n");
		token = (char *)my_strtok(string1, string2); 
		printf("%s\n", token);
		while (token != NULL)
		{

			token = my_strtok( NULL, string2);
			printf("%s\n", token);
		}
		printf("Want to continue...[Yy || Nn] : ");
		scanf("\n%c", &option);
		getchar();
	}while (option == 'Y' || option == 'y');
	return 0;
}
//Defining the my_strtok function
void *my_strtok(char *str, const char *delim)
{
	size_t j, count = 0;
	static char *position;
	size_t len, len1;
	char *token;
	if (str)
		position = str;
	token = position;
	len = strlen(delim);
	while(*position)
	{
		count++;
		for (j = 0; j < len; j++)
		{
			if (delim[j] == *position && delim[j] != '\0' )
			{
				*position = '\0';
				++position;
				if(j == len - 1)
					return token;
			}
			position++;
		}
	}
	if(*position)
	{
		return token;
	}
	else
		return NULL;
}
