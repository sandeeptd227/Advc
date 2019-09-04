#include "common.h"
//Defining print_hash function
void save_database(hash_t array[])
{
	data_t i;
	FILE *fs = fopen("backup.txt", "w");
//	fseek(fs, 0L, SEEK_END);
	for(i = 0; i < SIZE; i++)
	{
		hash_t *temp = &array[i];
		if(strcmp(array[i].word, "#") == 0)
		{
			continue;
		}
		fprintf(fs, "#%d\n", i);
		while(temp)
		{
			fprintf(fs,"	%s %d files  ", temp->word, temp->flcount);
			files_t *temp2 = temp->tablink;
			while(temp2)
			{
				fprintf(fs,"%s->%d ", temp2->fname, temp2->wordcount);
				temp2 = temp2->link;
			}
			fprintf(fs, "\n");
			temp = temp->wordlink;
		}
	}
	fclose(fs);
}
