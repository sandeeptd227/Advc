#include "common.h"
int validate_inputs(char **argv)
{
	//Checking for number of arguments
	size_t i, no_of_arg = 0;
	for( i = 0; argv[i]; i++)
		no_of_arg++;
	//Throw error if number of arguments are not equal to 4 or 5
	if (no_of_arg < 4 || no_of_arg > 5)
	{
		printf("Insufficient input\n");
		printf("Usage\n");
		printf("./steganography <option1> <option2> <option3> <option4>\n");
		printf("Option1 : -e for encryption and -d for decryption\n");
		printf("Option2 : Any source file with .bmp extension\n");
		printf("Option3 : Any text file with .txt extension\n");
		printf("Option4 : It is optional. Give any file with .bmp extension if needed\n");
		return ERROR;
	}
	//Checking for the input mode for encryption or decryption
	if(strncmp(argv[1], "-e", 2) != 0 && strncmp(argv[1], "-d", 2) != 0)
	{
		printf("No encryption or decryption selected\n");
		printf("Usage\n");
		printf("./steganography <option1> <option2> <option3> <option4>\n");
		printf("Option1 : -e for encryption and -d for decryption\n");
		return ERROR;	
	}
	//Checking if the source file is of .bmp extension
	size_t len = strlen(argv[2]);
	if(strcmp(argv[2] + (len - 3), "bmp") != 0)
	{
		printf("Source file not of .bmp extension\n");
		printf("Usage\n");
		printf("./steganography <option1> <option2> <option3> <option4>\n");
		printf("Option2 : Any source file with .bmp extension\n");
		return ERROR;
	}
	//Checking the source file if it is a .bmp format file
	FILE *fp;
	if((fp = fopen(argv[2], "rb")) == NULL)
	{
		perror("fopen");
		printf("Given source file do not exist\n");
		return ERROR;
	}
	unsigned short code;
	fread(&code, 2, 1, fp);
	if(code != 0x4d42)
	{
		printf("Source file is not a .bmp formatted file\n");
		fclose(fp);
		return ERROR;
	}
	fclose(fp);
	//Checking for text file
	len = strlen(argv[3]);
	if(strcmp(argv[3] + (len - 3), "txt") != 0)
	{
		printf("Option3: File is not of .txt extension\n");
		printf("Usage\n");
		printf("./steganography <option1> <option2> <option3> <option4>\n");
		printf("Option3 : Any text file with .txt extension\n");
		return ERROR;
	}
	//Checking for the destination file if given
	if(argv[4] != NULL)
	{
		len = strlen(argv[4]);
		if(strcmp(argv[4] + (len - 3), "bmp") != 0)
		{
			printf("Option4: File is not of .bmp extension\n");
			printf("Usage\n");
			printf("./steganography <option1> <option2> <option3> <option4>\n");
			printf("Option4 : Any text file with .bmp extension\n");
			return ERROR;
		}
		FILE *fd;
		if((fd = fopen(argv[4], "rb")) == NULL)
		{
			perror("fopen");
			printf("Given destination file do not exist\n");
			printf("Creating destination file\n");
			fd = fopen(argv[4], "wb");
			return SUCCESS;
		}
		unsigned short code;
		fread(&code, 2, 1, fd);
		if(code != 0x4d42)
		{
			printf("Destination file is not a .bmp formatted file\n");
			fclose(fd);
			return ERROR;
		}
		fclose(fd);
	}
	else
	{
		if (strcmp(argv[1], "-e") == 0) 
		{
			printf("Destination file not given\n");
			printf("Usage\n");
			printf("./steganography <option1> <option2> <option3> <option4>\n");
			printf("Option4 : Any text file with .bmp extension\n");
		}
	}
	return SUCCESS;
}
