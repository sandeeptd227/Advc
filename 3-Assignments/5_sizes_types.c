/* 
Title       : 5_sizes_basic_data_types.c
Author      : Sandeep
Date        : 25 May 2019
Description : Printing the sizes of all basic data types including modifiers for integral data types
Input       : Nothing
output      : Sizes in bytes for basic data types  
 */

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int main()
{
	//clear the screen
	system("clear");

	//writing statements for printing sizes of basic data types
	printf("Note : Size in bytes\n\n");
	printf("size of(char): %zu\n", sizeof(char));
	printf("size of(signed char): %zu\n", sizeof(signed char));
	printf("size of(unsigned char): %zu\n\n", sizeof(unsigned char));

	printf("size of(int): %zu\n", sizeof(int));
	printf("size of(signed int): %zu\n", sizeof(signed int));
	printf("size of(unsigned int): %zu\n\n", sizeof(unsigned int));

	printf("size of(short int): %zu\n", sizeof(short int));
	printf("size of(long int): %zu\n", sizeof(long int));
	printf("size of(long long int): %zu\n\n", sizeof(long long int));

	printf("size of(short unsigned int): %zu\n", sizeof(short unsigned int));
	printf("size of(long unsigned int): %zu\n", sizeof(long unsigned int));
	printf("size of(long long unsigned int): %zu\n\n", sizeof(long long unsigned int));

	printf("size of(float): %zu\n", sizeof(float));
	printf("size of(double): %zu\n", sizeof(double));
	printf("size of(long double): %zu\n", sizeof(long double));
	return 0;
}
