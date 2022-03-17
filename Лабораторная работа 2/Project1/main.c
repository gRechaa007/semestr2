#include<stdio.h>
#include<stdlib.h>
#include"operation.h"

int main()
{
	char operat;
	printf_s("Enter name of file whith matrix  and operation..  ");

	scanf_s("%c", &operat);


	for (int i = 0; i < x.size1; i++)
	{
		for (int j = 0; j < x.size2; j++)
		{
		   printf_s("%d", x.matrix[i][j]);
		}
	}
	Matrix x = matrx();


}
Matrix matrx()
{
	Matrix matrix;
	char name[20] = { 0 };
	gets(name);
	FILE* matrixx;
	if (fopen_s(&matrixx, name, "r"))
		perror("");
	int widht = 1;
	int lenght = 0;
	int smb = fscanf_s(matrixx, "%ñ", &smb);
	for (int i = 0; smb != EOF; i++)
	{
		int;
		while ( = fscanf_s(matrixx, "%d", &smb) != '\n')
			lenght++;
		if (smb = '\n')
			widht++;
		char smb = fgetc(matrixx);
	}
	lenght++;
	widht++;
	int** array = (int**)malloc(sizeof(int*) * lenght);
	for (int i = 0; i < lenght;i++)
	{
		array[i] = (int*)malloc(sizeof(int) * widht);
	}
	matrix.matrix = array;
	fread(array, sizeof(char), lenght * widht, matrixx);
	matrix.size1 = lenght;
	matrix.size2 = widht;
	return matrix;
	
}