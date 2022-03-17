#pragma once

#include<stdio.h>
#include<stdlib.h>

struct Matrix
{
	int rows;
	int cols;
	int** matrix;
};

typedef struct Matrix Matrix;

Matrix matrix(char* fileName);