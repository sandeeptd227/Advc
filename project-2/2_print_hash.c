#include "common.h"
//Defining print_hash function
void print_hash(hash_t array[])
{
	data_t i;
	for(i = 0; i < SIZE; i++)
	{
		hash_t *temp = &array[i];
		if(strcmp(array[i].word, "#") == 0)
		{
			continue;
		}
		printf("#%d\n", i);
		while(temp)
		{
			printf("	%s %d files  ", temp->word, temp->flcount);
			files_t *temp2 = temp->tablink;
			while(temp2)
			{
				printf("%s->%d ", temp2->fname, temp2->wordcount);
				temp2 = temp2->link;
			}
			printf("\n");
			temp = temp->wordlink;
		}
	}
}
