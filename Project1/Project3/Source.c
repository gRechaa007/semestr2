#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	int arr[2][3];
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 3;++j)
		{
			arr[i][j] = rand() % 100;
			printf("\t%d", arr[i][j]);
		}
		printf("\n");
	}
	int k, znak = 0;
	scanf_s("%d", &k);
	int* arr1;
	arr1 = (int*)malloc(k * sizeof(int));
	for (int i = 0; i < k; i++)
	{
		znak = rand() % 2;
		arr1[i] = znak == 1 ? arr1[i] = rand() % k : (rand() % k) * (-1);
	}

	for (int i = 0; i < k; i++)
	{
		printf("%d ", arr1[i]);
	}
}