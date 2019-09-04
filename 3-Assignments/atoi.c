#include <stdio.h>
#include <stdlib.h>

int my_atoi(const char *);
int main()
{
	char ch[] = "1234";
	int num;
	num = my_atoi(ch);
	printf("num = %d\n",  num);

}
int my_atoi(const char *p)
{
	int num = 0, digit;

	while (*p)
	{
		num = num * 10 + *p++ - '0';
	}
return num;
}
//int my_itoa (int num, char *str)
//int getword(char *str)
