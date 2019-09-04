/*
Title       : 48_swap_macro.c
Author      : Sandeep
Date        : 11 July 2019
Description : Swapping two items of any datatype using MACROS
Input       : Any two values/characters/strings as per selection of input datatype
Output      : Printing after swapping
 */
#include <stdio.h>
#include <stdlib.h>
//Defining the macro
#define GENERIC_SWAP( a, b, type) { type temp = a;\
	a = b;\
	b = temp;}
//Starting main
int main()
{
	//Declaring variables
	char c1, c2, option;
	int i1, i2, choice;
	float f1, f2;
	double d1, d2;
	do
	{
		//Clear the screen
		system("clear");
		char *p1 = NULL, *p2 = NULL, s1[] = {'\0'}, s2[] = {'\0'};
		//Prompt + read the choice of datatype
		printf("Select the type of input\n1. Character\n2. Integer\n3. Float\n4. Double\n5. String\n");
		scanf("%d", &choice);
		switch (choice)
		{
			case 1:
				//Prompt + read two characters
				printf("Enter two characters : ");
				scanf("\n%c\n%c", &c1, &c2);
				getchar();
				//Call generic swap using macros
				GENERIC_SWAP(c1, c2, char);
				printf("After swapping c1 : %c\tc2 : %c\n", c1, c2);
				break;
			case 2:
				//Prompt + read two integers
				printf("Enter two integers : ");
				scanf("%d%d", &i1, &i2);
				//Call generic swap using macros
				GENERIC_SWAP(i1, i2, int);
				printf("After swapping i1 : %d\ti2 : %d\n", i1, i2);
				break;
			case 3:
				//Prompt + read two float values
				printf("Enter two float values : ");
				scanf("%f%f", &f1, &f2);
				//Call generic swap using macros
				GENERIC_SWAP(f1, f2, float);
				printf("After swapping f1 : %f\tf2 : %f\n", f1, f2);
				break;
			case 4:
				//Prompt + read two double values
				printf("Enter two double values : ");
				scanf("%lf%lf", &d1, &d2);
				//Call generic swap using macros
				GENERIC_SWAP(d1, d2, double);
				printf("After swapping d1 : %lf\td2 : %lf\n", d1, d2);
				break;
			case 5:
				//Prompt + read two strings
				printf("Enter two strings : ");
				scanf("%s", s1);
				scanf("%s", s2);
				p1 = s1;
				p2 = s2;
				//Call generic swap using macros
				GENERIC_SWAP(p1, p2, char *);
				printf("After swapping s1 : %s\ts2 : %s\n", p1, p2);
				break;
			default:
				printf("Invalid choice\n");
		}
		printf("Want to continue....[ y | n ] ? ");
		scanf("\n%c", &option);
	}while (option == 'Y' || option == 'y' );
}
