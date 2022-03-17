#pragma once
#include <stdio.h>
#include <stdlib.h>

int reading();
int chek_symbol(symbol);
int counting(file, col, line, smb);
int mallMem(file, line, col, matrix);

struct Matrix
{
	int line;
	int col;
	int** matrix;
};

typedef struct Matrix Matrix;