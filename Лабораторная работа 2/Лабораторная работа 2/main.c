#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include"operation.h"

int main()
{
	printf_s("Enter matrix with operation(+,-,*,def,trs)..  ");
	char operat;
	scanf_s("%c", &operat);
	Matrix x = matrx();
	Matrix y;
	if (operat == '+' || operat == '-' || operat == '*')
	{
		y = matrx();
	}
	else if (operat == 'def' || operat == 'trs') {}
	else {
		printf_s("нет такого оператора, иди нахуй");
		return -1;
	}

	int result;
	switch (operat)
	{
		printf_s("Enter file names with matrix..  ");
	case'+':
		result = sum(x, y);
		break;
	case'-':
		result = deff();
		break;
	case'*':
		result = multy();
		break;
	}


	/*for (int i = 0; i < x.size1; i++)
	{
		for (int j = 0; j < x.size2; j++)
		{
		   printf_s("%d", x.matrix[i][j]);
		}
	}*/

	clean(x);
	clean(y);

}



Matrix matrx()
{
	int symbol;
	Matrix matrix;
	FILE* in;
	char name[20] = { 0 };
	printf_s("Enter a string:\n");
	getchar();
	gets_s(name, 20);

	if (fopen_s(&in, name, "r"))
		perror("");
	long currentPosition = ftell(in);
	while (fscanf_s(in, "%c", &symbol, 1) != EOF)
	{
		while (symbol != ' ' || symbol != '\n')
		{
			if (symbol != '-')
			{
				fseek(in, 0, SEEK_SET);
				if (symbol < '0' || symbol>'9')
				{
					printf("There is no matrix in the file");
					exit(0);
				}
			}
			fseek(in, currentPosition, SEEK_SET);
			if ((symbol = ' '))
				fscanf_s(in, "%c", &symbol, 1);

		}

	}



	int col = 1;
	int line = 1;
	int numberMatrx = 0;
	int smb = fgetc(in);


	for (int i = 0; smb != EOF; i++)
	{

		while (smb = fgetc(in) != '\n')
			if (smb == ' ')
				col++;

		if (smb == '\n')
			line++;
		char smb = fgetc(in);
	}
	
	int** array = (int**)malloc(sizeof(int*) * line);
	for (int i = 0; i < line;i++)
	{
		array[i] = (int*)malloc(sizeof(int) * col);
	}
	matrix.matrix = array;
	fread(array, sizeof(char), line * col, in);
	matrix.line = line;
	matrix.col = col;
	fclose(in);

	return matrix;
}
int clean(Matrix matrix)
{
	for (int i = 0; i < matrix.line; i++)
		for (int j = 0; j < matrix.col; j++)
			free(matrix.matrix[i][j]);
}
int matrixZ(int line, int col, Matrix matrix)
{

	int** arrayY = (int**)malloc(sizeof(int*) * line);
	for (int i = 0; i < line;i++)
	{
		arrayY[i] = (int*)malloc(sizeof(int) * col);
	}
	matrix.matrix = arrayY;
} 
