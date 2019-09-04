/* 
Title       : 22_word_count.c 
Author      : Sandeep
Date        : 4 July 2019
Description : Finding the number of characters, words and lines in the given input from the command line
Input       : Any input from terminal
output      : Character count, Word count and Line count  
 */

#include <stdio.h>
#include <stdlib.h>
//Starting main function
int main()
{

	//Declaring the variables 
	int ch_count = 0, line = 0, word = 0;
	//Clear the screen
	system("clear");
	int c, last_c = 0;
	while ((c = getchar()) != EOF)
	{
		last_c = c;
		//Counting lines if new line character is encountered
		if (c == '\n')
			line++;
		//Counting words
		if ((c == ' ' || c == '\n' ) && (last_c != ' ' && last_c != '\n'))
		{
			word++;
		}
		//Counting the characters
		ch_count++;
	}
	//Printing output
	printf("Charcater count : %d\n", ch_count);
	printf("Line count : %d\n", line);
	printf("Word count : %d\n", word);
	return 0;
}
