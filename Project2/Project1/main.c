#include<stdio.h>
#include<stdlib.h>
int main(int argc, char* argv[])
{
	int N, M;
	N = atoi(argv[1]);
	M = atoi(argv[2]);
	printf_s("%d", N * M - 1);
}