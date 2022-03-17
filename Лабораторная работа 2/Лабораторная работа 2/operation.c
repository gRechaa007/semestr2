#include<stdio.h>
#include<stdlib.h>
#include"operation.h"
int sum(Matrix x, Matrix y)
{
	if ((x.line == y.line)&&(x.col == y.col))
	{
		for (int i = 0; i < x.line; i++)
		{
			for (int j = 0; j < x.col; j++)
			{
				printf_s("%d", x.matrix[i][j] + y.matrix[i][j]);
			}
		}
	}
	else
	printf_s("Matrix sum is not possible.");
	return 0;
}

int deff(Matrix x, Matrix y)
{
	
		if ((x.line == y.line) && (x.col == y.col))
		{
			for (int i = 0; i < x.line; i++)
			{
				for (int j = 0; j < x.col; j++)
				{
					printf_s("%d", x.matrix[i][j] - y.matrix[i][j]);
				}
			}

		}
		else
			printf_s("Matrix sum is not possible.");
	
}

int multy()
{
	Matrix x = matrx();
	Matrix y = matrx();
	if ((x.line == y.line) && (x.col == y.col))
	{
		for (int i = 0; i < x.line; i++)
		{
			for (int j = 0; j < x.col; j++)
			{
				printf_s("%d", x.matrix[i][j] + y.matrix[i][j]);
			}
		}

	}
	else
	printf_s("Matrix sum is not possible.");
}

