#include <stdio.h>
#include <stdlib.h>
#define line 6
#define col 5

int main() 
{
	int arr[line][col];
	int* arr1 = *arr;
	for (int i = 0; i <= line * col - 1; i++)
	{
		int l = i / col + 1;
		int c = i % col + 1;
		arr1[i] = l * c;

	}
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf_s("%d\t", arr[i][j]);
		}
		printf_s("\n");
	}
}