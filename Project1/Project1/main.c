#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int main() 
{
	srand(time(NULL));
	int A, B;
	int* arrA, * arrB;
	scanf_s("%d%d", &A, &B);
	arrA = (int*)malloc(A * sizeof(int));
	arrB = (int*)malloc(B * sizeof(int));
	for (int i = 0, znak = 0; i < A;++i) {
		znak = rand() % 2;
		if (znak == 1) {
			arrA[i] = rand() % 20 + 10;
		}
		else {
			arrA[i] = (rand() % 20 + 10) * (-1);
		}
	}
	for (int i = 0; i < A; i++)
	{
		printf("%d ", arrA[i]);
	}
	printf("\n");
	for (int i = 0, tmp = 0; i < B;) {
		tmp = rand() % A;
		if (arrA[tmp] == 0) {
			continue;
		}
		else {
			arrB[i] = arrA[tmp];
			arrA[tmp] = 0;
			i++;
		}
	}
	for (int i = 0; i < B; i++)
	{
		printf("%d ", arrB[i]);
	}
	free(arrA);
	free(arrB);
}