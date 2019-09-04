/* 
Title       : 49_structure.c 
Author      : Sandeep
Date        : 6 July 2019
Description : Declaring structure to read details of students like name, roll number and marks obtained in different subjects and finding average and grade 
Input       : Student name, roll number and marks
output      : Printing details of students along with their average marks and grade  
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Defining a structure for student using typedef
typedef struct
{
	char *name;
	int roll_no;
	float *marks;
	float avg;
	char grade;
}student_t;
//Declaring the functions
void populate(student_t *p, size_t m, size_t n);
void avg_grade(student_t *p, size_t m, size_t n);
void print_details(student_t *p, size_t m, size_t n);
int search_rollnum(size_t rno, student_t *p, size_t m, size_t n, size_t *pos);
int my_strcmp(char *str1, char *str2);
int search_name(char *string, student_t *p, size_t m, size_t n, size_t *pos);
//Starting the main
int main()
{
	//Declaring the variables 
	char option, name[] = {'\0'};
	size_t m, n, pos, i;
	int choice, rno, status;
	do
	{
		//Clear the screen
		system("clear");
		//Enter the number of students, subjects and store it in the variables
		printf("Enter number of students : ");
		scanf("%zu", &m);
		printf("Enter number of subjects : ");
		scanf("%zu", &n);
		//Dynamically allocate memory for each student
		student_t *p = malloc(m * sizeof(student_t));
		if (!p)
		{
			perror("malloc");
			return 0;
		}
		//Populate the each student by calling populate function
		populate (p, m, n);
		//Calling avg_grade function to find average and grade
		avg_grade(p, m, n);
		//Prompt the user to select the mode of printing the details of student
		printf("SELECT ANY ONE\n1. Using ROLL NUMBER\n2. Using STUDENT NAME\n3. All students details\n");
		scanf("%d", &choice);
		//Switch case for printing the details of student
		switch (choice)
		{
			case 1:
				//If you select the roll number 
				//Enter the search roll number
				printf("Enter the roll number : ");
				scanf("%d", &rno);
				status = search_rollnum(rno, p, m, n, &pos);
				//Printing the details of the student if the roll number is found in the list
				if (status)
				{
					printf("Student Name : %s\n", p[pos].name);
					printf("Roll Number : %d\n", p[pos].roll_no);
					for(i = 0; i < n; i++)
					{
						printf("Marks in Subject %zu : %f\n", i + 1, *(p[pos].marks + i));
					}
					printf("Average : %f\n", p[pos].avg);
					printf("Grade : %c\n", p[pos].grade);
				}
				else
					printf("Your search did not match any documents\n");
				break;
			case 2:
				//If you select the student name as search key
				//Enter the search key
				printf("Enter Student name : ");
				scanf("%s", name);
				getchar();
				status = search_name(name, p, m, n, &pos);
				//Printing the details of the student if the student name is found in the list
				if (status)
				{
					printf("Student Name : %s\n", p[pos].name);
					printf("Roll Number : %d\n", p[pos].roll_no);
					for(i = 0; i < n; i++)
					{
						printf("Marks in Subject %zu : %f\n", i + 1, *(p[pos].marks + i));
					}
					printf("Average : %f\n", p[pos].avg);
					printf("Grade : %c\n", p[pos].grade);
				}
				else
					printf("Your search did not match any documents\n");
				break;
			case 3:
				//Printing the details of all the students
				print_details(p, m, n);
				break;
			default:
				printf("Invalid choice\n");
		}
		printf("Want to continue...[Yy || Nn] : ");
		scanf("\n%c", &option);
	}while (option == 'Y' || option == 'y');
	return 0;
}
//Defining the populate function
void populate(student_t *p, size_t m, size_t n)
{
	size_t i, j, size;
	char buffer[20] = {'\0'};
	//Read the names, marks, roll numbers of students
	for(i = 0; i < m; i++)
	{
		printf("Enter Student name %zu : ", i + 1);
		scanf("%s", buffer);
		//Finding the length of student and dynamically allocating memory for name
		size = strlen (buffer);
		p[i].name = malloc(size + 1);
		strcpy(p[i].name, buffer);
		printf("Enter Roll number : ");
		scanf("%d", &p[i].roll_no);
		//Dynamically allocating memory for 'n' subject marks
		p[i].marks = malloc(n * sizeof(float));
		//Reading marks
		for(j = 0; j < n; j++)
		{
			printf("Enter marks of Subject %zu : ", j + 1);
			scanf("%f", p[i].marks + j);
		}
		memset(buffer, '\0', 20);
		printf("\n");
	}
}
//Defining the avg_grade function
void avg_grade(student_t *p, size_t m, size_t n)
{
	size_t i, j;
	float sum;
	for(i = 0; i < m; i++)
	{
		sum = 0;
		for(j = 0; j < n; j++)
		{
			sum += *(p[i].marks + j);
		}
		//Finding average of all subjects
		p[i].avg = sum / n;
		//Finding grade
		if (p[i].avg >= 90)
			p[i].grade = 'A';
		else if (p[i].avg >= 80 && p[i].avg < 90)
			p[i].grade = 'B';
		else if (p[i].avg >= 70 && p[i].avg < 80)
			p[i].grade = 'C';
		else if (p[i].avg >= 60 && p[i].avg < 70)
			p[i].grade = 'D';
		else if (p[i].avg >= 50 && p[i].avg < 60)
			p[i].grade = 'E';
		else
			p[i].grade = 'F';
	}
}
//Defining the print_details
void print_details(student_t *p, size_t m, size_t n)
{
	size_t i, j;
	for (i = 0; i < m; i++)
	{
		printf("Student Name : %s\n", p[i].name);
		printf("Roll Number : %d\n", p[i].roll_no);
		for (j = 0; j < n; j++)
		{
			printf("Subject %zu marks : %f\n", j + 1, *(p[i].marks + j) );
		}
		printf("Average : %f\n", p[i].avg);
		printf("Grade : %c\n\n", p[i].grade);
	}
}
//Defining the search_rollnum function to find the student
int search_rollnum(size_t rno, student_t *p, size_t m, size_t n, size_t *pos)
{
	size_t i;
	int count = 0;
	for(i = 0; i < m; i++)
	{
		if(rno == p[i].roll_no)
		{
			count++;
			//If the student is found save the position of student
			*pos = i;
			break;
		}
	}
	if(count)
		return 1;
	else 
		return 0;
}
//Defining the search_name function to find the student
int search_name(char *string, student_t *p, size_t m, size_t n, size_t *pos)
{
	size_t i;
	int count = 0;
	for(i = 0; i < m; i++)
	{
		if(my_strcmp (string, p[i].name) == 0)
		{
			//If the student is found save the position of student
			count++;
			*pos = i;
			break;
		}
	}
	if(count)
		return 1;
	else 
		return 0;
}
//Defining the string comparision function
int my_strcmp(char *str1, char *str2)
{
	int i;
	for(i = 0; *(str1 + i) && *(str2 +i); i++)
	{
		//if characters are same or inverting the 6th bit makes them     same
		if(*(str1 + i) == *(str2 + i) || (*(str1 + i) ^ 32) == *(str2     + i))
			continue;
		else
			break;
	}
	if (*(str1 + i) == *(str2 + i))
		return 0;
	if ((*(str1 + i )|32) < (*(str2 + i)|32))
		return -1;
	return 1;
}

