#include "common.h"
//Defining the search_database function
void search_database(hash_t array[], char_t key)
{
	//Declare variables
	data_t index;
	//Finding the index
	if(isupper(key[0]))
	{
		index = (key[0] - 13) % 26;
	}
	else if(islower(key[0]))
	{
		key[0] = toupper(key[0]);
		index = (key[0] - 13) % 26;
	}
	else 
	{
		index = key[0] - 48;
	}
	hash_t *temp = &array[index];
	if(strcmp(temp->word, "#") == 0)
	{
		printf("No data found\n");
		return;
	}
	while(temp)
	{
		if(strcmp(temp->word, key) == 0)
		{
			printf("	%s %d files ", temp->word, temp->flcount);
			files_t *temp2 = temp->tablink;
			while(temp2)
			{
				printf("%s->%d", temp2->fname, temp2->wordcount);
				temp2 = temp2->link;
			}
			printf("\n");
			return;
		}
		temp = temp->wordlink;
	}
	printf("Key not found\n");
}
