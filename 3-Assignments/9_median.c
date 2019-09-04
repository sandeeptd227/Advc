/* 
Title       : 9_median.c 
Author      : Sandeep
Date        : 12 June 2019 
Description : Reading two different unsorted arrays, finding median for those two arrays and finally finding the average of two medians
Input       : Two arrays, Number of terms in first and second array
output      : Sorted arrays, Medians for two arrays and average of two medians of the given arrays  
 */

#include <stdio.h>
#include <stdlib.h>

//declare the functions
float median( int *, int);
void print(int *, int);
void sorting(int *, int);
void populate(int *, int);

int main()
{

	//declaring the variables 
	char option;
	int num1, num2, status;
	float average, median1, median2;
	do
	{
		//clear the screen
		system("clear");
		//enter the number of terms for two arrays  and store them in the variables
		printf("enter the number of terms for 1st and 2nd array : ");
		status = scanf("%d%d", &num1, &num2);
		//validating input
		if (status != 2 || num1 <= 0 || num2 <= 0)
		{
			printf("invalid number of terms\n");
			return 0;
		}
		//declaring 1st array
		int a[num1];
		printf("enter the 1st array values\n");
		//calling populate function to store values in the 1st array
		populate(a, num1);
		//declaring 2nd array
		int b[num2];
		printf("enter the 2nd array values\n");
		//calling populate function to store values in the 2nd array
		populate(b, num2);
		//sorting 1st array
		printf("\nfirst array after sorting\n");
		sorting(a, num1);
		print(a, num1);
		//sorting 2nd array
		printf("\n2nd array after sorting\n");
		sorting(b, num2);
		print(b, num2);
		//calling median function for 1st array
		median1 = median(a, num1);
		printf("\nmedian of 1st array = %f\n", median1);
		//calling median function for 2nd array
		median2 = median(b, num2);
		printf("\nmedian of 2nd array = %f\n", median2);
		//finding the average of two medians 
		average = (median1 + median2) / 2.0f;
		printf("\naverage of two medians = %f\n", average);

		printf("want to continue...[Yy || Nn] : ");
		scanf("\n%c", &option);
	}while (option == 'Y' || option == 'y');
	return 0;
}

//defining populate function
void populate(int *p, int num)
{
	int i;
	for (i = 0; i < num; i++)
	{
		scanf("%d", p++);
	}
}
//defining sorting function
void sorting(int *p, int num)
{
	int i, j, temp;
	for(i = 0; i < num; i++)
	{
		for(j = i; j < num; j++)
		{
			if ( *(p+i) > *(p+j))
			{
				temp = *(p+i);
				*(p+i) = *(p+j);
				*(p+j) = temp;
			}
		}
	}
}
//defining print function to print values in the array
void print(int *p, int num)
{

	int i;
	for(i = 0; i < num; i++)
	{
		printf("%d\t", *(p + i));
	}
	printf("\n");
}
//defining median function to find median of an array
float median( int *p, int num)
{
	float median;
	if ( num % 2)
	{
		median = *(p+(num/2)); 
	}
	else
	{
		median = ((*(p+num/2)) + (*(p+(num/2) -1)) ) / 2.0f ;
	}
	return median;
}
