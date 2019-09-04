#include <stdio.h>

int main()
{
	static int num, res = 1;
	printf("enter the number : ");
	scanf("%d", &num);
	if (num == 1)
	{
		return res;
	}
	else
	{
		res = num * main();
		num--;
	}
	printf("%d\n", res);


}
