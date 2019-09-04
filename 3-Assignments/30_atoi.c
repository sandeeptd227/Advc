/* 
Title       : 30_atoi.c 
Author      : Sandeep
Date        : 27 June 2019
Description : Executing atoi, itoa, strlen functions
Input       : For atoi - Any Number as a string
			  For itoa - Any number
			  For getword - Any string
output      : For atoi - Print the given number string in decimal form
              For itoa - Print given number in character form
              For getword - Print length of the given string
 */

#include <stdio.h>
#include <stdlib.h>

//Declaring the functions
int my_atoi(const char *);
size_t getword(const char *);
char * itoa(int);
void reverse( char *, size_t);
//Starting main function
int main()
{

	//Declaring the variables 
	char option;
	int num, choice;
	char ch[80];
	do
	{
		//Clear the screen
		system("clear");
		//Enter the choice of operation and store it in the variable
		printf("Select any option\n1.atoi\n2.itoa\n3.getword\n");
		scanf("%d", &choice);
		//Switch case to execute different functions
		switch( choice )
		{
			case 1:
				printf("Enter a number as string : ");
				scanf("%s", ch);
				//Calling atoi function
				num = my_atoi(ch);
				//Printing result in decimal form
				printf("num = %d\n", num);
				break;
			case 2:
				printf("Enter any number\n");
				scanf("%d", &num);
				//Calling itoa function
				char *cptr = itoa(num);
				printf("Printing given number as a string\n");
				printf("%s\n", cptr);
				break;
			case 3:
				printf("Enter any string\n");
				getchar();
				scanf("%[^\n]s", ch);
				//Calling getword function to find the string length
				size_t len = getword(ch);
				printf("Length of given string: %lu\n", len);
				break;
			default:
				printf("Invalid choice\n");
				break;
		}
		printf("Want to continue...[Yy || Nn] : ");
		scanf("\n%c", &option);
	}while (option == 'Y' || option == 'y');
	return 0;
}

//Defining atoi function
int my_atoi(const char *ptr)
{
	int num = 0, digit;
	//Converting ascii to integers using ascii values
	while(*ptr)
	{
		num = num * 10 + *ptr++ - '0';
	}
	return num;
}

//Defining getword function
size_t getword(const char *str)
{
	int count = 0;
	while (*str)
	{
		//Counting the length of string
		count++;
		str++;
	}
	return count;
}
//Defining itoa function
char * itoa(int num)
{
	static char asci[] = {'\0'};
	int i = 0, digit;
	while (num)
	{
		//Converting each digit into character
		digit = num % 10;
		asci[i] = digit + '0';
		i++;
		num /= 10;
	}
	//Calling reverse function to reverse the character array
	reverse(asci, getword(asci));
	return asci;
}
//Defining the reversing the character array function
void reverse( char *str, size_t length)
{
	size_t start, end;
	char temp;
	for(start = 0, end = length - 1; start <= end; ++start, --end)
	{
		//Swapping the elements of the character array to get reverse of the array
		temp = *(str + start);
		*(str + start) = *(str + end);
		*(str + end) = temp;
	}
}

