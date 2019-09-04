/* 
Title       : 10_calendar.c
Author      : Sandeep
Date        : 25 May 2019
Description : Printing the n'th day from the given day 
Input       : Any number from 1 to 365
output      : n'th day from given day   
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	//clear the screen
	system("clear");

	//declaring the variables 
	int startday,days,totaldays,oddday;

	//enter the startday, store it in the variable and validating
	printf("choose the start day\n");
	printf("1.Sunday 2.Monday 3.Tuesday 4.Wednesday 5.Thursday 6.Friday 7.Saturday\n");
	scanf("%d",&startday);
	if (startday < 1 || startday > 7 )
	{
		printf("choosen option for startday is invalid\n");
		exit(1);
	}

	//enter the number of days, store it in the variable and validating
	printf("enter the number of days\n");
	scanf("%d",&days);
	if (days < 1 || days > 365)
	{
		printf("Entered number of days is invalid\n");
		exit(2);
	}

	//logic for finding the odd day for given number of days by making the starting day as sunday 
	printf("%d th day : ", days);
	totaldays = days + startday-1;
	oddday = totaldays % 7;
	switch (oddday)
	{
		case 0:
			printf("Saturday\n");
			break;
		case 1:
			printf("Sunday\n");
			break;
		case 2:
			printf("Monday\n");
			break;
		case 3:
			printf("Tuesday\n");
			break;
		case 4:
			printf("wednesday\n");
			break;
		case 5:
			printf("Thursday\n");
			break;
		case 6:
			printf("Friday\n");
			break;
		default:
			printf("invalid\n");
	}
	return 0;
}
