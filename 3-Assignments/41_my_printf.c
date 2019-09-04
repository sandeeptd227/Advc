/* 
Title       : 41_my_printf.c 
Author      : Sandeep
Date        : 17 July 2019
Description : Executing printf function
Input       : Any number or chracters from the keyboard 
output      : Printing the entered input  
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

//Declaring function
void myprintf(const char *, ...);
int main()
{

	//Declaring the variables 
	char option;
	char ch;
	int num;
	float fl_num;
	double double_num;
	do
	{
		//Clear the screen
		system("clear");
		//Enter the values of different data types and store it in the respective variables
		myprintf("Enter a integer : ");
		scanf("%d", &num);
		myprintf("Enter a float : ");
		scanf("%f", &fl_num);
		myprintf("Enter a double : ");
		scanf("%lf", &double_num);
		myprintf("Enter a character : ");
		scanf("\n%c", &ch);
		getchar();
		//Printing the output using myprintf function
		myprintf("Value in ch = %c\n", ch);
		myprintf("Value in num = %d", num);
		myprintf("Value in fl_num = %f", fl_num);
		myprintf("Value in double_num = %lf", double_num );

		myprintf("Want to continue...[Yy || Nn] : ");
		scanf("\n%c", &option);
	}while (option == 'Y' || option == 'y');
	return 0;
}

//Declaring myprintf function
void myprintf(const char *format, ...)
{
	va_list ap;
	char ch, *ptr = NULL;
	int a;
	float b;
	double d;
	const char *p = format;
	//Starting variadic function
	va_start(ap, format);
	char buffer[80] = {'\0'};
	while (*p)
	{
		if(*p == '%')
		{
			//Starting switch case for each format specifier
			switch (*++p)
			{
				case 'c':
					//Printing characters
					ch = (char)va_arg(ap, int);
					putchar(ch);
					break;
				case 'd':
					//Printing integers
					a = va_arg(ap, int);
					sprintf(buffer, "%d", a);
					puts(buffer);
					break;
				case 'f':
					//Printing floating
					b = va_arg(ap, double);
					sprintf(buffer, "%f", b);
					puts(buffer);
					break;
				case 'l' :
					//Printing double
					d = va_arg(ap, double);
					sprintf(buffer, "%lf", d);
					puts(buffer);
					p++;
					break;
			}
		}
		else
		{
			putchar(*p);
		}
		p++;
	}
	va_end(ap);
}
