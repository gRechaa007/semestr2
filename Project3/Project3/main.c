#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i = 0;
	while (i < 10)
	{
		i++;
		printf_s("%d\n", i);
	}
	/*for (int i = 0; i < 10; ++i)
	{
		printf("%i", i);
	}*/
	return 0;
}