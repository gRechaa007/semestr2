#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <errno.h>

int input();
void binary(int* Arr, int num);
int sum();
//void output();

int main()
{
	int Arr[32] = {0};
	errno = 0;
	printf_s("Enter files first name:  ");
	long int num = input();
	if (errno != 0)
		return 0;
	printf("%d\n\n", num);
	for (int i = 0;i < 32;i++) {
		printf("%d", Arr[i]);
	}
	printf_s("Enter files second name:  ");
	char arr1[100] = { 0 };
	FILE* output;
	gets(arr1);
	fopen_s(&output, arr1, "w");
	int summa = sum() ;
	binary(Arr, num);
	for (int i = 0;i < 32;i++) {
		fprintf(output, "%d", Arr[i]);
		printf("%d", Arr[i]);
	}
	printf("\n");
	printf_s("%d", summa);
	fclose(output);
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
	else {
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
		if (count > 10) {
			printf("Number is ery big!!");
			exit(0);
		}
		fseek(input, 0, SEEK_SET);
		fscanf_s(input, "%lld", &number);
		if (number > INT_MAX) {
			printf("Number is ery big");
			exit(0);
		}
		if (number < INT_MIN) {
			printf("Number is very small");
			exit(0);
		}
		fclose(input);
	}
	return number;
}

//void output(int num)
//{
//	int summ = sum(num);
//	int arr1[32] = { 0 };
//	FILE* output;
//	fopen_s(&output, "output.txt", "w");
//	fprintf(&output, "%d", summ);
//	fclose(output);
//}

void binary(int* Arr, int num)
{
	if (num < 0) {
		num = abs(num);
		Arr[0] = 1;
	}
	else
		Arr[0] = 0;
	//двоичное представление числа
	for (int i = 31; i > 0; i--)
	{
		Arr[i] = num % 2;
		num = num / 2;
	}
	if (Arr[0] == 1) {
		// обратный код числа
		for (int i = 1; i < 32; i++) {
			if (Arr[i] == 0)
				Arr[i]++;
			else Arr[i]--;
		}
		// доп код числа
		for (int i = 31; i > 0; i--) {
			if (Arr[i] == 0) {
				Arr[i] = 1;
				break;
			}
			else
				Arr[i] = 0;
		}
	}
}

int sum()
{
	int num = input();
	int s = 0;
	if (num > 0)
	{
		while (num != 0)
		{
			s = s + num % 10;
			num = num / 10;
		}
	}
	else
	{
		num = num * (-1);
		while (num != 0)
		{
			s = s + num % 10;
			num = num / 10;
		}
		s = s * (-1);
	}
	return s;
}