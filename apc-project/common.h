#ifndef COMMON_H
#define COMMON_H
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SWAP(a, b) { int temp = a;\
  a = b;\
  b = temp;}
typedef int data_t;
typedef struct node
{
	data_t data;
	struct node *prev;
	struct node *next;
}dlist;
enum status
{
	FAILURE,
	SUCCESS,
	LIST_EMPTY,
};
int insert_at_first(dlist **head, dlist **tail, data_t data);
int print_list(dlist *head);
void four_digits(int array[], size_t length, dlist **head, dlist **tail);
int addition(dlist **tail1, dlist **tail2, dlist **head3, dlist **tail3);
void subtraction(dlist **tail1, dlist **tail2, dlist **head3, dlist **tail3);
void print_result(dlist *head);
#endif
