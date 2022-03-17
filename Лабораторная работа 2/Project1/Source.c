#include "operat.h"



int main() 
{
	printf_s("Enter namefile of matrix :..\n");
	reading();
	Matrix x ;
	




	printf_s("Enter operation:..\n");
	char operat;
	scanf_s("%c", &operat, 1);

}


//int schit()
//{
//	FILE* file;
//	char nameMass[20]="matrixA.txt";
//	//char* mass;
//	int smb;
//	//mass = gets(nameMass);
//	if (fopen_s(&file, nameMass, "r"))
//		perror("");
//	while (smb = fgetc(file)) {
//		if (smb != EOF) {
//			if (check_symbol(smb, file) == 1)
//				printf_s("%c ", smb);
//			else
//				printf_s("no matrix in the file");
//			if (smb == ' ')
//				getchar();
//			else
//				printf_s("no matrix in the file");
//		}
//	}
//
//}
//
//int check_symbol(int symbol, FILE* file) {
//	if (symbol != '-')
//		fseek(file, 0, SEEK_SET);
//	else if (symbol > '0' || symbol < '9') {
//		//printf_s("no matrix in file\n");
//		return 1;
//	}
//	else
//		return -1;
//}
//int schet()
//{
//
//}