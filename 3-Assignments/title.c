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

int main()
{

	//Declaring the variables 
	char option;
	do
	{
		//Clear the screen
		system("clear");
		//Enter the number and store it in the variable
		//Logic
		printf("Want to continue...[Yy || Nn] : ");
		scanf("\n%c", &option);
	}while (option == 'Y' || option == 'y');
	return 0;
}
