
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int sort(int argc, int* mass, int* arr)
{
	for (int i = 0; i < argc - 2; i++) {
		for (int j = 0; j < argc - 3; j++) {
			if (mass[j] < mass[j + 1]) {
				int tmp1 = mass[j];
				mass[j] = mass[j + 1];
				mass[j + 1] = tmp1;
				int tmp2 = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp2;
			}
		}
	}
}

int main(int argc, char* argv[]) {
	int N = atoi(argv[1]);
	if (N > (argc - 2)) {
		printf("Error\n");
		return 1;
	}
	int mass[100] = { 0 };
	int* arr = (int*)malloc((argc - 2) * sizeof(int));

	for (int i = 0;i < argc - 2;i++) {
		arr[i] = i;
	}
	for (int i = 0;i < argc - 2;i++) {
		mass[i] = strlen(argv[i + 2]);
	}

	sort(int argc, int mass[], int* arr);

	int* arr1 = (int*)malloc(N * sizeof(int));
	for (int i = 0;i < N;i++) {
		arr1[i] = arr[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N - 1; j++) {
			if (arr1[j] > arr1[j + 1]) {
				int tmp3 = arr1[j];
				arr1[j] = arr1[j + 1];
				arr1[j + 1] = tmp3;
			}
		}
	}
	for (int i = 0;i < N;i++) {
		printf("%s ", argv[arr1[i] + 2]);
	}
	free(arr);
	free(arr1);
	return 0;
}