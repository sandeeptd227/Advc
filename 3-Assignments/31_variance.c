/* 
Title       : 31_variance.c 
Author      : Sandeep
Date        : 4 July 2019 
Description : Finding the variance of the elements
Input       : Any number of elements in the array
output      : Variance of elements in the array  
 */

#include <stdio.h>
#include <stdlib.h>

//Declaring the functions
void populate(int *aptr, int num);
void variance_array(int *aptr, int num, float *mean, float *variance);
void mean_array(int *aptr, int num, float *mean);
//Starting main
int main()
{
	//Declaring the variables 
	char option;
	int elements, status, choice;
	float mean = 0;
		float variance;
	do
	{
		//Clear the screen
		system("clear");
		//Enter the number of elements and store it in the variable
		printf("Enter the number of elements : ");
		status = scanf("%d", &elements);
		if(status != 1)
		{
			printf("Invalid input\n");
			return 0;
		}
		printf("Select type of memory allocation\n1.Static\n2.Dynamic\n");
		scanf("%d", &choice);
		//Declaring the array using static memory allocation
		int array[elements];
		//Declaring the array using dynamic memory allocation
		int *dyn_array = (int *)malloc(elements * sizeof(int));
		//Switch case
		switch (choice)
		{
			case 1:
				//Array is passed using static memory allocation
				printf("Enter the array values\n");
				//Calling populate function to store values in the array
				populate(array, elements);
				//Calling variance function to find variance
				variance_array(array, elements, &mean, &variance);
				//Printing the output
				printf("Variance is %f\n", variance);
				break;
			case 2:
				//Array is passed using dynamic memory allocation
				printf("Enter the array values\n");
				//Calling populate function to store values in the array
				populate(dyn_array, elements);
				//Calling variance function to find variance
				variance_array(dyn_array, elements, &mean, &variance);
				//Printing the output
				printf("Variance is %f\n", variance);
				break;
			default:
				printf("Invalid choice\n");
		}
		printf("Want to continue...[Yy || Nn] : ");
		scanf("\n%c", &option);
	}while (option == 'Y' || option == 'y');
	return 0;
}
//Defining the populate function
void populate(int *aptr, int num)
{
	int i;
	for(i = 0; i < num; i++)
	{
		scanf("%d", aptr++);
	}
}
//Defining the varaiance function
void variance_array(int *aptr, int num, float *mean, float *variance)
{
	float diff, sum = 0;
	int i;
	//Finding the sum of elements
	for(i = 0; i < num; i++)
	{
		sum += *(aptr + i);
	}
	//Finding the mean
	*mean = sum / num;
	sum = 0;
	//Finding difference between each element and mean first
	//Square the difference
	//Repeat this for all elements
	//Find average of all differences which will give variance
	for(i = 0; i < num; i++)
	{
		diff = *(aptr + i) - *mean;
		diff = diff * diff;
		sum += diff;
	}
	*variance = sum / num;
}
