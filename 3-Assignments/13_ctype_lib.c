/* 
Title       : 13_ctype_lib.c 
Author      : Sandeep
Date        : 19 June 2019
Description : Creating own Ctype library function
Input       : Any input from keyboard
output      : To display the output of selected ctype library function  
 */

#include <stdio.h>
#include <stdlib.h>

//declaring the functions
int isalnum1(char);
int isalpha1(char);
int isascii1(char);
int isblank1(char);

int main()
{
	//declaring the variables 
	char option, ch, choice, res;
	int status;
	do
	{
		//clear the screen
		system("clear");
		//enter the number/alphabet/special symbol and store it in the variable
		printf("Enter the input : ");
		scanf("%c", &ch);
		//selecting the choice
		printf("Select an option\n1.Isalnum\n2.Isalpha\n3.Isascii\n4.Isblank\n");
		status = scanf("%hhd", &choice);
		if(status != 1)
		{
			printf("Invalid input\n");
			return 0;
		}
		switch (choice)
		{
			case 1:
				//calling the isalnum function to check if the given input is alpha-numeric or not
				res = isalnum1(ch);
				if (res) 
					printf("Given input  alpha-numeric\n");
				else
					printf("Given input  not alpha-numeric\n");
				break;
			case 2:
				//calling the isalpha function to check if the given input is alphabet or not
				res = isalpha1(ch);
				if (res) 
					printf("Given input alphabet\n");
				else
					printf("Given input not alphabet\n");
				break;
			case 3:
				//calling the isascii function to check if the given input is a valid ascii value or not
				res = isascii1(ch);
				if (res) 
					printf("Given input is valid ascii value\n");
				else
					printf("Given input is not a valid ascii value\n");
				break;
			case 4:
				//calling the isblank function to check if the given input ascii value gives a blank character or not
				res = isblank1(ch);
				if (res) 
					printf("Given input blank character\n");
				else
					printf("Given input  not blank character\n");
				break;
			default:
				printf("Invalid choice\n");
		}
		printf("Want to continue...[Yy || Nn] : ");
		scanf("\n%c", &option);
		getchar();
	}while (option == 'Y' || option == 'y');
	return 0;
}
//defining the isalnum function
int isalnum1(char ch)
{
	if (ch >= 65 && ch <= 90 || ch >= 97 && ch <= 122 || ch >= 48 && ch <= 57)
		return 1;
	else
		return 0;
}
//defining the isalpha function
int isalpha1(char ch)
{
	if (ch >= 65 && ch <= 90 || ch >= 97 && ch <= 122)
		return 1;
	else
		return 0;
}
//defining the isascii function
int isascii1(char ch)
{
	if (ch >= 0 && ch <= 127)
		return 1;
	else
		return 0;
}
//defining the isblank function
int isblank1(char ch)
{
	if (ch == 9 || ch == 32)
		return 1;
	else
		return 0;
}

