#include "common.h"

int decryption(char **argv)
{
	FILE *fd, *ft;
	int text_length, status;
	fd = fopen(argv[2], "rb");
	fseek(fd, 54L, 0);
	//Checking passcode by calling decrypt_passcode function
	status = decrypt_passcode(fd);
	if (status == ERROR)
	{
		printf("Password Wrong\n");
		return ERROR;
	}
	printf("Password matched\n");
	//Length of secret file decrypted by calling decrypt_length function 
	status = decrypt_length(fd, &text_length);
	if (status == ERROR)
	{
		printf("Decryption of length of the secret file failed\n");
		return ERROR;
	}
	printf("Decryption of length of the secret file success\n");
	ft = fopen(argv[3], "wb");
	//Calling decrypt_secret function for decryption of secret file
	status = decrypt_secret(fd, ft, text_length);
	if (status == ERROR)
	{
		printf("Decryption of secret file contents failed\n");
		return ERROR;
	}
	printf("Decryption of secret file contents success\n");
	return SUCCESS;
}
//Defining the decrypt_password function 
int decrypt_passcode(FILE *fd)
{
	//Declare variables
	unsigned int passcode;
	//Prompt + read the password at the user end
	printf("Enter passcode : ");
	scanf("%d", &passcode);
	//Check whether the password is matched or not
	int	original = 0, i;
	char f;
	//Decrypt Original passcode
	for(i = 31;i >= 0; i--)
	{
		fread(&f, 1, 1, fd);
		if (f & 0x01)
		{
			original = original | 1 << i;
		}
	}
	if(original == passcode)
		return SUCCESS;
	else 
		return ERROR;
}
//Defining the decrypt_length function to decrypt the length of the secret file
int decrypt_length(FILE *fd, int *length)
{
	//Declare variables
	int	text_length = 0, i;
	char f;
	//Decrypt text file length
	for(i = 31;i >= 0; i--)
	{
		fread(&f, 1, 1, fd);
		if (f & 0x01)
		{
			text_length = text_length | 1 << i;
		}
	}
	*length = text_length;
	return SUCCESS;
}
//Define the decrypt_secret function to decrypt the secret file
int decrypt_secret(FILE *fd, FILE *ft, int text_length)
{
	//Declare variables
	int i, j; 
	char f;
	for(i = 1; i <= text_length; i++)
	{
		char text = 0;
		int k = 7;
		//Decrypt each character which is stored in LSBs of 8bytes
		for(j = 1; j <= 8; j++)
		{
			fread(&f, 1, 1, fd);
			if (f & 0x01)
				text = text |  0x01 << k;
			k--;
		}
		fwrite(&text, 1, 1, ft);
	}
	return SUCCESS;
}
