/*
Title       : 18_averg.c
Author      : Sandeep
Date        : 18 July 2019
Description : Finding mean of numbers mentioned as a environment variable and command line arguments based on the selection
Input       : Select one in envirnmental variable method or Command line arguments
Output      : Mean
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void env_average(char *cptr, int *sum, float *mean);
int main(int argc, char *argv[], char *env[])
{
	//Declare variables
	int i, choice, sum = 0, count, envcount = 0;
	float mean;
	//Selecting the choice
	printf("Enter your choice\n1.Environment variables\n2.Command line argumnets\n");
	scanf("%d", &choice);
	switch (choice)
	{
		case 1:
			//Environmental variables
			for(i = 0; env[i]; i++)
			{
				//Checking whether the given env variable exists or not
				if(strncmp(env[i], argv[1], 5) == 0)
				{
					envcount++;
					printf("Match found : %s\n", env[i]);
					env_average(env[i], &sum, &mean);
					printf("Mean : %f\n", mean);
				}
			}
			//If the env variable is not found
			if (envcount == 0)
				printf("Match for given environmental variable not found\n");
			break;
		case 2:
			//Command line arguments
			count = 0;
			for (i = 1; argv[i]; i++)
			{
				sum += atoi(argv[i]);
				count++;
			}
			mean = (float) sum / count;
			printf("Mean : %f\n", mean);
			break;
		default:
			printf("Invalid selection\n");
	}
}
//Defining env_average function to find the mean
void env_average(char *cptr, int *sum, float *mean)
{
	char *token;
	int count = 0;
	strtok(cptr, "=");
	while ((token = strtok(NULL, ",")) != NULL)
	{
		count++;
		*sum += atoi(token);
		token = strtok(NULL, ",");
	}
	*mean = (float) *sum / count;
}
