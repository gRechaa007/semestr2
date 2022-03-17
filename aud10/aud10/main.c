#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int count = 0;
	FILE* someText;
	char nameFile[8] = { 0 };
	printf_s("Enter files name: ");
	gets(nameFile);
	if (fopen_s(&someText, nameFile, "r"))
	{
		perror("");
		system("pause");
		return (-1);
	}
	int size = 0;
	char smb = fgetc(someText);
	for (int i = 0; smb != -1; i++)
	{
		smb = fgetc(someText);
		size++;
		if (smb == '\n') {
			count++;
		}
	}
	char* array = (char*)malloc(size * (sizeof(char)));
	rewind(someText);

	fread(array, sizeof(char), size, someText);
	freopen(nameFile, "w", someText);
	fprintf_s(someText, "%d\n", count + 2);
	fprintf_s(someText, "%s", array);
	fclose(someText);
	system("pause");
	return 0;
	ty_jopa;
}

