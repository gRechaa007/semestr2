#pragma once


typedef struct Matrix
{
	int line;
	int col;
	int** matrix;
}Matrix;

Matrix matrx();
int sum();
int deff();
int multy();