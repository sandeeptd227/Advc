#include <stdio.h>
#include <stdarg.h>

void myprintf(const char *, ...);
int main()
{
	char ch = 'A';
	myprintf("The value of ch : %c\n", ch);
	int a = 10;
	myprintf("The value of a : %d", a);
}

void myprintf(const char *format, ...)
{
	va_list ap;
	char ch;
	int a;
	const char *p = format;
	va_start(ap, format);
	char buffer[80] = {'\0'};
	while (*p)
	{
		if(*p == '%')
		{
			switch (*++p)
			{
				case 'c':
				ch = (char)va_arg(ap, int);
				putchar(ch);
				break;
				case 'd':
				a = va_arg(ap, int);
				sprintf(buffer, "%d", a);
				puts(buffer);
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
