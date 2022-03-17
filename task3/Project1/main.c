#include <stdio.h>
#define ARRAY_SIZE 10

int main()
{
	int mass[10] = { 0 };
	int arr[5] = { 0 };
	for (int i = 0; i < 10;i++)
	{
		scanf_s("%d", &mass[i]);
	}

	for (int j = 0; j < 10; ++j) {
		for (int i = 1; i < 10; i++) {
			if (mass[i] < mass[i - 1]) {
				int tmp = mass[i];
				mass[i] = mass[i - 1];
				mass[i - 1] = tmp;
			}
		}
	}
	for (int i = 0; i < 10;i++)
	{
		printf("%d ", mass[i]);
	}
	printf("\n");
	for (int i = 5; i < 10; i++)
	{
		printf("%d ", mass[i]);
	}
	for (int i = 5;i < 10; i++)
	{
		mass[i-5] = arr[i];
	}
	printf("\n");
	for (int i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}
	
}