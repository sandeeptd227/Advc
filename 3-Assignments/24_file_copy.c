/* 
Title       : 24_file_copy.c 
Author      : Sandeep
Date        : 29 June 2019
Description : Copying contents in source file to a destination file using fopen, fread, fwrite commands
Input       : Source file name
output      : Source file contents in Destination file  
 */

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
//Declaring the functions
void my_file_copy(FILE *fs,  FILE *fd);

//Starting main function
int main(int argc, char *argv[])
{

	//Declaring the variables 
	char option, buffer[80] = {'\0'};
	FILE *fs, *fd;
	//Clear the screen
	system("clear");
	//Opening the source file in read mode 
	fs = fopen(argv[1], "r"); 
	if (fs == NULL)
	{
		perror(argv[1]);
		return 0;
	}
	//Opening the destination file in write mode 
	fd = fopen(argv[2], "w"); 
	if (fd == NULL)
	{
		perror(argv[1]);
		return 0;
	}
	//Calling the my_file_copy function to copy contents in source file to destination
	my_file_copy(fs, fd);
	fcloseall();
	return 0;
}
//Defining the my_file_copy function
void my_file_copy(FILE *fs, FILE *fd)
{
	char buffer[80] = {'\0'};
	size_t bytes;
	//Copying the contents in source file to destination file
	while (0 < (bytes = fread(buffer, 1, sizeof(buffer), fs)))
	{
		fwrite(buffer, 1, sizeof(buffer), fd);
	}
}
