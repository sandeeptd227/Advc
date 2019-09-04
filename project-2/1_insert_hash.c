#include "common.h"
int insert_hash(hash_t array[], char sample[], char_t filename)
{
	//Declare variables
	data_t index, i;
	//Finding the index
	if(isupper(sample[0]))
	{
		index = (sample[0] - 13) % 26;
	}
	else if(islower(sample[0]))
	{
		sample[0] = toupper(sample[0]);
		index = (sample[0] - 13) % 26;
	}
	else if(isdigit(sample[0]))
	{
		index = sample[0] - 48;
	}
	else
	{
		return FAILURE;
	}
	hash_t *temp = &array[index];
	files_t *new_file;
	if(strcmp(temp->word, "#") == 0)
	{
		temp->word = malloc((strlen(sample)+1) * sizeof(char));
		strcpy(temp->word, sample);
		temp->flcount = 1;
		new_file = malloc(sizeof(files_t));
		//Update tablink values
		new_file->fname = malloc((strlen(filename)+1) * sizeof(char));
		strcpy(new_file->fname, filename);
		new_file->wordcount = 1;
		new_file->link = NULL;
		temp->tablink = new_file;
		return SUCCESS;
	}
	while(temp)
	{
		if(strcmp(temp->word, sample) == 0)
		{
			files_t *temp2 = temp->tablink;
			//Traverse to the filename to increment the count
			while(temp2)
			{
				if(strcmp(temp2->fname, filename) == 0)
				{
					(temp2->wordcount)++;
					return SUCCESS;
				}
				if(temp2->link == NULL)
				{
					(temp->flcount)++;
					files_t *new2_file = malloc(sizeof(files_t));
					//Update tablink values
					new2_file->fname = malloc((strlen(filename)+1) * sizeof(char));
					new2_file->fname = filename;
					new2_file->wordcount = 1;
					new2_file->link = NULL;
					temp2->link = new2_file;
					return SUCCESS;
				}
				temp2 = temp2->link;
			}
		}
		 if(temp->wordlink == NULL)
		{
			break;
		}
		temp = temp->wordlink;
	}
	//Create new node
	hash_t *new1 = malloc(sizeof(hash_t));
	files_t *new1_file;
	if (new1 == NULL)
	{
		return FAILURE;
	}
	//Update new values if new word is found
	new1->word = malloc((strlen(sample)+1) * sizeof(char));
	strcpy(new1->word, sample);
	new1->wordlink = NULL;
	new1->flcount = 1;
	new1_file = malloc(sizeof(files_t));
	//Update tablink values
	new1_file->fname = malloc((strlen(filename)+1) * sizeof(char));
	strcpy(new1_file->fname, filename);
	new1_file->wordcount = 1;
	new1_file->link = NULL;
	new1->tablink = new1_file;
	temp->wordlink = new1;
	return SUCCESS;
}
