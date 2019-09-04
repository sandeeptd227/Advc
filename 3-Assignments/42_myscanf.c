/* 
Title       : 42_myscanf.c 
Author      : Sandeep
Date        : 18 July 2019
Description : Executing our own scanf function
Input       : Any input 
output      : Display the input which is read using myscanf function
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
//Declaring functions
void myscanf(const char *format, ...);
//Starting main
int main()
{

	//Declaring the variables 
	char option;
	do
	{
		char ch;
		int num;
		float fl_num;
		double dl_num;
		//Clear the screen
		system("clear");
		//Prompt + read the diiferent values
		printf("Enter a integer : ");
		myscanf("%d", &num);
		printf("Enter a float number : ");
		myscanf("%f", &fl_num);
		printf("Enter a double number : ");
		myscanf("%lf", &dl_num);
		printf("Enter a character : ");
		myscanf("%c", &ch);
		getchar();
		//Printing the output
		printf("\nInteger : %d\n", num);
		printf("Float number : %f\n", fl_num);
		printf("Double number : %lf\n", dl_num);
		printf("Character : %c\n", ch);

		//Logic
		printf("Want to continue...[Yy || Nn] : ");
		myscanf("\n%c", &option);
		getchar();
	}while (option == 'Y' || option == 'y');
	return 0;
}
//Defining myscanf function
void myscanf(const char *format, ...)
{
	va_list ap;
	const char *p = format;
	//Initialize arg list
	va_start (ap, format);

	//Declaring the pointer variables
	char *cptr = NULL;
	int *iptr = NULL;
	float *fptr = NULL;
	double *dptr = NULL;
	char buffer[80] = {'\0'};

	while (*p)
	{
		if (*p == '%')
		{
			//Switch case for different format specifiers
			switch (*++p)
			{
				case 'c':
					//For character
					cptr = va_arg(ap, char *);
					*cptr = getchar();
					break;
				case 'd':
					//For integer 
					fgets(buffer, 10, stdin);
					iptr = va_arg(ap, void *);
					*iptr = atoi(buffer);
					break;
				case 'f':
					//For float number
					fgets(buffer, 10, stdin);
					fptr = va_arg(ap, float *);
					*fptr = atof(buffer);
					break;
				case 'l':
					p++;
					if(*p == 'f')
					{
						fgets(buffer, 10, stdin);
						dptr = va_arg(ap, double *);
						*dptr = atof(buffer);
					}
			}
		}
		else
			putchar(*p);
		p++;
	}
	va_end(ap);
}
