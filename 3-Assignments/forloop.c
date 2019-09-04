#include <stdio.h>

int main()
{
	int i, j;
	for (i = 0; i < 1; ++i)
	{
		printf("%d\n", i);
		for (j= 0; j < 1; j++)
		{
		printf("%d\n", i);
		}
	}
	
		printf("last value %d\n", i);
}
