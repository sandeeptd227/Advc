/* 
Title       : 43_tower_hanoi.c 
Author      : Sandeep
Date        : 27 June 2019
Description : Executing tower of hanoi
Input       : Any number
output      : Steps for executing the tower of hanoi method  
 */

#include <stdio.h>
#include <stdlib.h>
//Declaring functions
void tofh (int ndisk, char source, char temp, char dest);
//Starting main function
int main()
{

	//Declaring the variables 
	char option, source = 'S', temp = 'T', dest = 'D';
	int ndisk, status;
	do
	{
		//Clear the screen
		system("clear");
		//Enter the number of disks and store it in the variable
		printf("Enter number of disks : ");
		status = scanf("%d", &ndisk);
		//Validating input
		if(status != 1)
		{
			printf("Invalid input\n");
			return 0;
		}
		printf("Sequence is\n");
		//Calling tower of hanoi function
		tofh(ndisk, source, temp, dest);
		printf("Want to continue...[Yy || Nn] : ");
		scanf("\n%c", &option);
	}while (option == 'Y' || option == 'y');
	return 0;
}
//Defining the tower of hanoi function
void tofh (int ndisk, char source, char temp, char dest)
{
	if (ndisk > 0)
	{
		tofh(ndisk - 1, source, dest, temp);
		printf("Move disk %d  %c ----> %c\n", ndisk, source, dest);
		tofh(ndisk - 1, temp, source, dest);
	}
}
