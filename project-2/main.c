#include "common.h"
//Starting main
int main(int argc, char *argv[])
{
	//Declare variables
	hash_t array[SIZE];
	data_t i, option, status;
	files_t file_tab, *head_ft = NULL;
	char update_file[30], key[20];
	//Inititialise indexes in hash table
	for (i = 0; i < SIZE; i++)
	{
		array[i].flcount = 0;
		array[i].word = "#";
		array[i].wordlink = NULL;
		array[i].tablink = head_ft;
	}
	FILE *fs;
	char sample[10];
	char filename[20];
	//Create a list of files
	if (argc > 1)
	{
	tab_t *file_list = NULL;
	for(i = 1; i < argc; i++)
	{
		insert_at_first(&file_list, argv[i]);
	}
	print_list(file_list);
	tab_t *create = file_list;

	while(1)
	{
		//Prompt + read the operation
		printf("Select one option\n1.Create data base\n2.Print database\n3.Update database\n4.Search database\n5.Save database\n6.Exit\n");
		scanf("%d", &option);
		switch (option)
		{
			case 1:
				//Create data base using all files
				while(create)
				{
					fs = fopen(create->flname, "r");
					while (fscanf(fs, "%s", sample) != EOF)
					{
						insert_hash(array, sample, create->flname);
					}
					fclose(fs);
					create = create->next_file;
				}
				printf("Database created\n");
				break;
			case 2:
				print_hash(array);
				break;
			case 3:
				//Updating the data base
				//Prompt + read the new file
				printf("Enter the filename : ");
				scanf("%s", update_file);
				//Check whether the file already exists in the data base
				status = search_file(file_list, update_file);
				if(status == FILE_NOT_FOUND)
				{
					fs = fopen(update_file, "r");
					while (fscanf(fs, "%s", sample) != EOF)
					{
						insert_hash(array, sample, update_file);
					}
					fclose(fs);
				}
				else
				{
					printf("File already exists\n");
				}
				break;
			case 4:
				//Search the key in the database
				//Prompt + read the key
				printf("Enter the key : ");
				scanf("%s", key);
				search_database(array, key);
				break;
			case 5:
				save_database(array);			
				break;
			case 6:
				return 0;
			default :
				printf("Invalid selection\n");
		}
	}
	}
	else
	{
		printf("No files given\n");
	}
	return 0;
}
