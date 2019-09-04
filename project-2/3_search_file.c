#include "common.h"
//Defining the search file function
int search_file(tab_t *file_list, char_t update_file)
{
	//Check for list empty
	if(file_list == NULL)
	{
		return FILE_NOT_FOUND;
	}
	//Check the whole list
	while(file_list)
	{
		if(strcmp(file_list->flname, update_file) == 0)
		{
			return FILE_FOUND;
		}
		file_list = file_list->next_file;
	}
	return FILE_NOT_FOUND;
}
