#ifndef COMMON_H
#define COMMON_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef int data_t;
typedef char * char_t;
typedef struct files
{
	char_t fname;
	data_t wordcount;
	struct files *link;
}files_t;
typedef struct word
{
	char_t word;
	data_t flcount;
	struct word *wordlink;
	struct files *tablink;
}hash_t;
enum status 
{
	FAILURE,
	SUCCESS,
	FILE_FOUND,
	FILE_NOT_FOUND,
};
typedef struct filename
{
	char_t flname;
	struct filename *next_file;
}tab_t;

#define SIZE 26
int insert_hash(hash_t array[], char sample[], char_t filename);
int insert_at_first(tab_t **head, char_t filename);
void print_hash(hash_t array[]);
int print_list(tab_t *head);
void save_database(hash_t array[]);
int search_file(tab_t *filelist, char_t update_file);
void search_database(hash_t array[], char_t key);
#endif
