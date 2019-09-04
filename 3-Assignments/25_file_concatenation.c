/* 
Title       : 25_file_concatenation.c 
Author      : Sandeep
Date        : 7 July 2019
Description : Copying contents in source file to a destination file using fgetc, fputc commands
Input       : Files input from command line 
output      : Source file contents in Destination file  
 */

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Declaring the functions
void my_file_copy(FILE *fs,  FILE *fd);
void filecat_1(struct _IO_FILE *stdin, struct _IO_FILE *stdout);
void filecat_2(FILE *fs, struct _IO_FILE *stdout);
void filecat_3(FILE *fs1, FILE *fs2, struct _IO_FILE *stdout);
void filecat_4(FILE *fs1, FILE *fs2, FILE *fd);

//Starting main function
int main(int argc, char *argv[])
{
	//Declaring file pointers
	FILE *fs1, *fd, *fs2;
	switch (argc)
	{
		//If no file is given as input
		case 1:
			//Calling filecat_1 function
			//Source is stdin and destination is stdout
			filecat_1(stdin, stdout);
			break;
			//If one source file is given in input
		case 2:
			fs1 = fopen(argv[1], "r"); 
			if (fs1 == NULL)
			{
				perror(argv[1]);
				return 0;
			}
			//Source is source file and destination is stdout
			//Calling filecat_2 function
			filecat_2(fs1, stdout);
			break;
			//If two files are given in input
		case 3:
			fs1 = fopen(argv[1], "r"); 
			if (fs1 == NULL)
			{
				perror(argv[1]);
				return 0;
			}
			fs2 = fopen(argv[2], "r"); 
			if (fs2 == NULL)
			{
				perror(argv[2]);
				return 0;
			}
			//Calling filecat_3 function
			//Two source files and destination is stdout
			filecat_3(fs1, fs2, stdout);
			break;
			//If two files are given in input and one destination file is given in input
		case 4:
			fs1 = fopen(argv[1], "r"); 
			if (fs1 == NULL)
			{
				perror(argv[1]);
				return 0;
			}
			fs2 = fopen(argv[2], "r"); 
			if (fs2 == NULL)
			{
				perror(argv[2]);
				return 0;
			}
			fd = fopen(argv[3], "a+"); 
			if (fd == NULL)
			{
				perror(argv[2]);
				return 0;
			}
			//Calling filecat_4 function
			filecat_4(fs1, fs2, fd);
			break;
		default:
			printf("Invalid input\n");
	}
	fcloseall();
	return 0;
}
//Defining function filecat_1
void filecat_1(struct _IO_FILE *stdin, struct _IO_FILE *stdout)
{
	int f;
	//Getting contents from stdin and writing to stdout
	do
	{
		f = fgetc(stdin);
		if(f != EOF)
			fputc(f, stdout);
		if (feof(stdin))
		{
			if (ferror(stdin))
			{
				perror(NULL);
			}
		}
	}while(f != EOF);
	printf("\n");
}
//Defining function filecat_2
void filecat_2(FILE *fs, struct _IO_FILE *stdout)
{
	int f;
	//Getting contents from source file and writing to stdout
	do
	{
		f = fgetc(fs);
		if(f != EOF)
			fputc(f, stdout);
		if (feof(fs))
		{
			if (ferror(fs))
			{
				perror(NULL);
			}
		}
	}while(f != EOF);
}
//Defining the filecat_3 function
void filecat_3(FILE *fs1, FILE *fs2, struct _IO_FILE *stdout)
{
	int f;
	//Getting contents from two source files and writing it in the stdout
	do
	{
		f = fgetc(fs1);
		if(f != EOF)
			fputc(f, stdout);
		if (feof(fs1))
		{
			if (ferror(fs1))
			{
				perror(NULL);
			}
		}
	}while(f != EOF);
	do
	{
		f = fgetc(fs2);
		if(f != EOF)
			fputc(f, stdout);
		if (feof(fs2))
		{
			if (ferror(fs2))
			{
				perror(NULL);
			}
		}
	}while(f != EOF);
}
//Defining function filecat_4
void filecat_4(FILE *fs1, FILE *fs2, FILE *fd)
{
	int f;
	//Getting contents from two source files and writing it to destination file
	do
	{
		f = fgetc(fs1);
		if(f != EOF)
			fputc(f, fd);
		if (feof(fs1))
		{
			if (ferror(fs1))
			{
				perror(NULL);
			}
		}
	}while(f != EOF);
	do
	{
		f = fgetc(fs2);
		if(f != EOF)
			fputc(f, fd);
		if (feof(fs2))
		{
			if (ferror(fs2))
			{
				perror(NULL);
			}
		}
	}while(f != EOF);
}
