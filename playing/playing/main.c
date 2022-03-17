#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <errno.h>

int input();
void binary(int* Arr, int num);
int sum(int num);
void output(int num, int* Arr);

int main()
{
	int Arr[32] = { 0 };
	errno = 0;
	printf_s("Enter files first name:  ");
	long long int num = input();
	if (errno != 0)
		return 0;
	int summa = sum(num);
	printf_s("Enter files second name:  ");
	binary(Arr, num);
	output(num, Arr);
	printf_s("\n%d", summa);
}

int input() {
	int count = 0;
	char symbol;
	long long int  number = 0;
	FILE* input;
	char arr[100] = { 0 };
	gets(arr);
	if (fopen_s(&input, arr, "r")) 
		perror("");
	else
	{
		fscanf_s(input, "%c", &symbol, 1);
		if (symbol != '-')
			fseek(input, 0, SEEK_SET);
		while (fscanf_s(input, "%c", &symbol, 1) != EOF)
		{
			if (symbol < '0' || symbol>'9')
			{
				printf("There is no number in the file");
				exit(0);
			}
			count++;
		}
		if (count > 10)
		{
			printf("Number is very big!");
			exit(0);
		}
		fseek(input, 0, SEEK_SET);
		fscanf_s(input, "%lld", &number);
		if (number > INT_MAX)
		{
			printf("Number is very big");
			exit(0);
		}
		if (number < INT_MIN)
		{
			printf("Number is very small");
			exit(0);
		}
		fclose(input);
	}
	return number;
}

void output(int num, int* Arr)
{
	FILE* output;
	char arr1[100] = { 0 };
	gets(arr1);
	if (fopen_s(&output, arr1, "w"))
		perror("");
	for (int i = 0;i < 32;i++)
	{
		printf("%d", Arr[i]);
		fprintf(output, "%d", Arr[i]);
	}
	fclose(output);
}

void binary(int* Arr, int num)
{
	if (num >= 0)
	{
		for (int i = 31; i > 0; i--)
		{
			Arr[i] = num % 2;
			num = num / 2;
		}
	}
	else {
		num = abs(num);
		for (int i = 31; i > 0; i--)
		{
			Arr[i] = num % 2;
			num = num / 2;
		}
		for (int i = 0; i < 32; i++)
		{
			if (Arr[i] == 0)
				Arr[i] = 1;
			else Arr[i] = 0;
		}
		for (int i = 31; i > 0; i--)
		{
			if (Arr[i] == 0) {
				Arr[i] = 1;
				break;
			}
			else
				Arr[i] = 0;
		}
	}
}

int sum(int num)
{
	int number = abs(num);
	int s = 0;
	while (number != 0)
	{
		s = s + number % 10;
		number = number / 10;
	}
	return s;
}