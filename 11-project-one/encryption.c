#include "common.h"
//Defining the encryption function
int encryption(char **argv)
{
	FILE *fs, *fd, *ft;
	unsigned int passcd, text_length;
	int status;
	fs = fopen(argv[2], "rb");
	//If there is no destination file mentioned
	if (argv[4] == NULL)
	{
		fd = fopen("default.bmp", "wb");
	}
	else
	{
		fd = fopen(argv[4], "wb");
	}
	ft = fopen(argv[3], "r");

	printf("ENCRYPTION BEGINS........\n");
	//Copying the header of source file
	status = header_copy(fs, fd);
	if (status == ERROR)
	{
		printf("Header encryption failed\n");
		return ERROR;
	}
	printf("Header encryption success\n");

	//Prompt + read passcode
	printf("Enter passcode : ");
	scanf("%d", &passcd);

	//Calling passcode function to encrypt passcode
	status = passcode(fs, fd, passcd);
	if (status == ERROR)
	{
		printf("Passcode encryption failed\n");
		return ERROR;
	}
	printf("Passcode encryption success\n");

	//Finding the length of secret text file and encrypt the length and write it in the destination file
	status = textfile_length(fs, fd, ft, &text_length);
	if (status == ERROR)
	{
		printf("Text file length encryption failed\n");
		return ERROR;
	}
	printf("Text file length encryption success\n");

	//Calling textfile_copy to encrypt the data of textfile
	status = textfile_copy(fs, fd, ft);
	if (status == ERROR)
	{
		printf("Text file contents encryption failed\n");
		return ERROR;
	}
	printf("Text file contents encryption success\n");

	//Copying the remaining contents from source to destination
	status = rem_copy(fs,fd);
	if (status == ERROR)
	{
		printf("Remaining contents encryption failed\n");
		return ERROR;
	}
	printf("Remaining contents encryption success\n");
	fclose(fd);
	fclose(fs);
	return SUCCESS;
}

//Defining the header_copy function to copy header of source to destination
int header_copy(FILE *fs, FILE *fd)
{
	char buffer[200]= {'\0'};
	fread(buffer, 1, 54, fs);
	fwrite (buffer, 1, 54, fd);
	return SUCCESS;
}
//Defining the passcode encrypting function
int passcode(FILE *fs, FILE *fd,int passcd)
{
	unsigned int mask = 1 << (sizeof(int) << 3) - 1;
	char f, s;
	for (; mask; mask >>= 1)
	{
		//Fetching the character from source file modify it and send it to the destination file
		fread(&f, 1, 1, fs);
		if(passcd & mask)
		{
			s = f | 0x01;
			fwrite(&s, 1, 1, fd);
		}
		else
		{
			s = f & 0xfe;
			fwrite(&s, 1, 1, fd);
		}
	}
}
//Defining textfile length function to encrypt the length of the text file
int textfile_length(FILE *fs, FILE *fd, FILE *ft, int *text_length)
{
	char f,s;
	size_t ch;
	int ch_count = 0;
	//Finding the length of the secret file
	while (ch = fread(&f, 1, 1, ft) != 0)
	{
		ch_count++;
	}
	//Encrypt length of the secret file
	unsigned int mask = 1 << (sizeof(int) << 3) - 1;
	for (; mask; mask >>= 1)
	{
		//Fetching the character from source file modify it and send it to the destination file
		fread(&f, 1, 1, fs);
		if(ch_count & mask)
		{
			s = f | 0x01;
			fwrite(&s, 1, 1, fd);
		}
		else
		{
			s = f & 0xfe;
			fwrite(&s, 1, 1, fd);
		}
	}
	rewind(ft);
	*text_length = ch_count;
	return SUCCESS;
}
//Defining the textfile copy function
int textfile_copy(FILE *fs, FILE *fd, FILE *ft)
{
	size_t ch;
	char s,f, text;
	while (ch = fread(&text, 1, 1, ft) != 0)
	{
		unsigned char mask = 1 << (sizeof(char) << 3) - 1;
		for (; mask; mask >>= 1)
		{
			//Fetching the character from source file modify it and send it to the destination file
			fread(&f, 1, 1, fs);
			if(text & mask)
			{
				s = f | 0x01;
				fwrite(&s, 1, 1, fd);
			}
			else
			{
				s = f & 0xfe;
				fwrite(&s, 1, 1, fd);
			}
		}
	}
	return SUCCESS;
}
//Defining rem_copy function to copy remaining contents from source file
int rem_copy(FILE *fs, FILE *fd)
{
	size_t ch;
	char f;
	while(ch = fread(&f, 1, 1, fs) != 0)
	{
		fwrite(&f, 1, 1, fd);
	}
	return SUCCESS;
}
