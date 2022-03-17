#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>

#define line 
#define col 10

int main(void) {
	int arr[col][line] = { 0 };
	for (int i = 1, j = 1; j < line;) 
	{
		if (i >= line) 
		{
			i = 1;
			++j;
			printf("\n");
		}
		else 
		{
			printf("\t%d ", i * j);
			++i;
		}
	}
	system("pause");
	return 0;
}
