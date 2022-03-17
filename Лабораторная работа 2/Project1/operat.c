#include"operat.h"

int reading() 
{
	FILE* file;
	char nameMass[20];
	int symbol;
	gets(nameMass);
	if (fopen_s(&file, nameMass, "r"))
		perror("");
	long currentPosition = ftell(file);
	while (fscanf_s(file, "%c", &symbol, 1) != EOF)
	{
		while (symbol != ' ' || symbol != '\n')
		{
			if (symbol != '-')
			{
				fseek(file, 0, SEEK_SET);
				if (symbol < '0' || symbol>'9')
				{
					printf("There is no matrix in the file");
					exit(0);
				}
			}
			fseek(file, currentPosition, SEEK_SET);
			if ((symbol = ' '))
				fscanf_s(file, "%c", &symbol, 1);

		}

	}
}

int check_symbol(int symbol)
{
	if (symbol != '-')
	{
		if (symbol > '0' || symbol < '9')
		{
			return 1;
		}
		else
			printf_s("no matrix in file\n");
	}
	else if (symbol == '-')
		return -1;
	else printf_s("no matrix in file\n");
	
}
int counting(FILE* file, int col, int line, int smb)
{
	reading();
	col = 1;
	line = 1;
	smb = fgetc(file);
	if (smb != EOF)
	{
		while (smb = fgetc(file) != '\n')
			if (smb == ' ')
				col++;
		if (smb == '\n')
			line++;
		//char smb = fgetc(file);
	}
}
int mallMem(FILE* file, int line, int col, Matrix matrix)
{
	//counting(file, line, col, smb);
	int** array = (int**)malloc(sizeof(int*) * line);
	for (int i = 0; i < line;i++)
	{
		array[i] = (int*)malloc(sizeof(int) * col);
	}
	matrix.matrix = array;
	fread(array, sizeof(char), line * col, file);
	matrix.line = line;
	matrix.col = col;
	fclose(file);

	return matrix.matrix;
}
int clean(Matrix matrix)
{
	for (int i = 0; i < matrix.line; i++)
		for (int j = 0; j < matrix.col; j++)
			free(matrix.matrix[i][j]);
}