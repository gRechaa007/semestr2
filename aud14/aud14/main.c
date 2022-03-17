#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
	int arr[256] = { 0 };
	int size = strlen(argv[1]);
	for (int i = 0;i < size;i++) {
		arr[(int)argv[1][i]]++;
	}
	int count = 0; 
	for (int i = 0;i < 256;i++) {
		if (arr[i] > 1) {
			count++;
		}
	}
	printf("\n %d", count);
	return 0;
}
