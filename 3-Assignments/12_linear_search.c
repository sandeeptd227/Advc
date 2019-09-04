/*
Title       : 12_linear_search.c
Author      : Sandeep
Date        : 29 June 2019
Description : Executing linear search for int, char, float, and double data types by following the prototype of inbuilt 'bsearch' function
Input       : Array of numbers of specified datatype and key to found
Output      : Printing key is found or not
 */

#include <stdio.h>
#include <stdlib.h>

//Declaring functions
void *my_searchi(const void *key, const void *base, size_t elements, size_t size, int (*funptr1)(const void *p, const void *q));
void *my_searchf(const void *key, const void *base, size_t elements, size_t size, int (*funptr2)(const void *p, const void *q));
void *my_searchc(const void *key, const void *base, size_t elements, size_t size, int (*funptr3)(const void *p, const void *q));
void *my_searchd(const void *key, const void *base, size_t elements, size_t size, double (*funptr4)(const void *p, const void *q));
int comparei(const void *p, const void *q);
int comparef(const void *p, const void *q);
int comparec(const void *p, const void *q);
double compared(const void *p, const void *q);

//Starting main
int main()
{
	//Declare variables
	int choice, elements, i, key;
	float float_key;
	char char_key, option;
	double double_key;
	void *index;
	do
	{
		//Clear screen
		system("clear");
		//Prompt to select the data type and store in the variable
		printf("Select data type\n1.Int\n2.Float\n3.Char\n4.Double\n");
		scanf("%d", &choice);
		//Prompt + read the number of elements 
		printf("Enter number of elements to read\n");
		scanf("%d", &elements);
		//Declaring arrays
		int array[elements];
		char char_array[elements];
		float float_array[elements];
		double double_array[elements];
		switch(choice)
		{
			case 1:
				//Enter values in the array
				printf("Enter the %d int values\n", elements);
				for (i = 0; i < elements; i++)
				{
					scanf("%d", array+ i );
				}
				//Enter search key
				printf("Enter key\n");
				scanf("%d", &key);
				//Calling my_search function
				index = (int *)my_searchi(&key, array, sizeof(array) / sizeof(array[0]), sizeof(array[0]), comparei);
				if(index != NULL)
					printf("Key found\n");
				else
					printf("key not found\n");
				break;
			case 2:
				//Enter values in the array
				printf("Enter the %d float values\n", elements);
				for (i = 0; i < elements; i++)
				{
					scanf("%f", float_array + i);
				}
				//Enter search key
				printf("Enter key\n");
				scanf("%f", &float_key);
				//Calling my_search function
				index = (float *)my_searchf(&float_key, float_array, sizeof(float_array) / sizeof(float_array[0]), sizeof(float_array[0]), comparef);
				if(index != NULL)
					printf("Key found\n");
				else
					printf("key not found\n");
				break;
			case 3:
				//Enter values in the array
				printf("Enter the %d char values\n", elements);
				for (i = 0; i < elements; i++)
				{
					scanf("\n%c", char_array+ i );
				}
				//Enter search key
				printf("Enter key\n");
				scanf("\n%c", &char_key);
				//Calling my_search function
				index = (char *)my_searchc(&char_key, char_array, sizeof(char_array) / sizeof(char_array[0]), sizeof(char_array[0]), comparec);
				if(index != NULL)
					printf("Key found\n");
				else
					printf("key not found\n");
				break;
			case 4:
				//Enter values in the array
				printf("Enter the %d double values\n", elements);
				for (i = 0; i < elements; i++)
				{
					scanf("%lf", double_array+ i );
				}
				//Enter search key
				printf("Enter key\n");
				scanf("%lf", &double_key);
				//Calling my_search function
				index = (double *)my_searchd(&double_key, double_array, sizeof(double_array) / sizeof(double_array[0]), sizeof(double_array[0]), compared);
				if(index != NULL)
					printf("Key found\n");
				else
					printf("key not found\n");
				break;
			default:
				printf("Invalid choice\n");
		}
		printf("Do you want to continue? (y / n) : ");
		scanf("\n%c", &option);
	}while(option == 'y' || option == 'Y');
}
//Defining linear search function for int data type
void *my_searchi(const void *key, const void *base, size_t elements, size_t size, int (*funptr1)(const void *p, const void *q))
{
	int res, i;
	for(i = 0; i < elements; i++)
	{
		//Calling compare function 
		res = funptr1(key, (int *)(base + i * size));
		if (res == 0)
			break;
	}
	if (res == 0)
		return (int *)base + i * size;
	else
		return NULL;
}
//Defining the compare function for int data type
int comparei(const void *p, const void *q)
{
	return (*(int *)p - *(int *)q);
}
//Defining linear search function for float data type
void *my_searchf(const void *key, const void *base, size_t elements, size_t size, int (*funptr2)(const void *p, const void *q))
{
	int res, i;
	for(i = 0; i < elements; i++)
	{
		//Calling compare function 
		res = funptr2(key, (float *)(base + i * size));
		if (res == 0)
			break;
	}
	if (res == 0)
		return (float *)base + i * size;
	else
		return NULL;
}
//Defining the compare of two values for float data types
int comparef(const void *p, const void *q)
{
	return (*(float *)p - *(float *)q);
}
//Defining linear search function for char data type
void *my_searchc(const void *key, const void *base, size_t elements, size_t size, int (*funptr3)(const void *p, const void *q))
{
	int res, i;
	for(i = 0; i < elements; i++)
	{
		//Calling compare function 
		res = funptr3(key, (char *)(base + i * size));
		if (res == 0)
			break;
	}
	if (res == 0)
		return (char *)base + i * size;
	else
		return NULL;
}
//Defining the compare of two values for char data types
int comparec(const void *p, const void *q)
{
	return (*(char *)p - *(char *)q);
}
//Defining linear search function for double data type
void *my_searchd(const void *key, const void *base, size_t elements, size_t size, double (*funptr4)(const void *p, const void *q))
{
	int i;
	double res;
	for(i = 0; i < elements; i++)
	{
		//Calling compare function 
		res = funptr4((double *)key, (double *)(base + i * size));
		if (res == 0)
			break;
	}
	if (res == 0)
		return (double *) base + i * size;
	else
		return NULL;
}
//Defining the compare of two values for double data types
double compared(const void *p, const void *q)
{
	return (*(double *)p - *(double *)q);
}
