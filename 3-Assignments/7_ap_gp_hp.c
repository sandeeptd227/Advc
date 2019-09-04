/* 
Title       : 7_ap_gp_hp.c
Author      : Sandeep
Date        : 29 May 2019
Description : Printing the AP, GP and HP if the starting number, number of terms and common difference/ratio are given
Input       : Starting number, number of terms and common difference/ratio
output      : Printing AP,GP and GP  
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	//clear the screen
	system("clear");

	//declaring the variables 
	char option;
	float hp;
	int startnum, terms, common, i, ap, gp;
	int status1, status2, status3;
	do
	{
		//enter the starting number, number of terms, common ratio/difference and store it in the variables
		printf("enter starting number\n");
		status1 = scanf("%d", &startnum);
		printf("enter number of terms\n");
		status2 = scanf("%d", &terms);
		printf("enter common ratio/difference\n");
		status3 = scanf("%d", &common);

		//validation for starting number, number of terms and common ratio/difference
		if (status1 != 1 || status2 !=1 || status3 != 1)
		{
			printf("invalid input\n");
			exit(1);
		}

		//initialising AP,GP and HP
		printf("AP\tGP\tHP\n");
		ap = startnum;
		gp = startnum;
		hp = 1.0f / startnum;

			//getting i'th term in ap , gp and hp
			for (i = 1; i <= terms; i++)
			{
				printf("%d\t%d\t%f\n",ap,gp,hp);
				ap = ap + common;
				gp = gp * common;
				hp = 1.0f / ap;
			}
		printf("want to continue...[Yy || Nn] : ");
		scanf("\n%c", &option);
	}while (option == 'Y' || option == 'y');
	return 0;
}
