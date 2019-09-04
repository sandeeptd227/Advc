#include "common.h"
int main(int argc, char *argv[])
{
	//Validate input... if there is error exit
	int status = validate_inputs(argv);
	if(status == ERROR)
	{
		printf("Error in input\n");
		return 0;
	}
	if (strcmp (argv[1], "-e") == 0)
	{
		//Encrypt the data
		status = encryption(argv);
		if (status == ERROR)
		{
			printf("ENCRYPTION FAILURE\n");
			return 0;
		}
		else
		{
			printf("ENCRYPTION SUCCESS\n");
		}
	}
	else
	{
		//Decrypt the data
		status = decryption(argv);
		if (status == ERROR)
		{
			printf("DECRYPTION FAILURE\n");
			return 0;
		}
		else
		{
			printf("DECRYPTION SUCCESS\n");
		}
	}
	return 0;
}
