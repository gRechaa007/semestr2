#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

int main()
{
	int j = 0;
	FILE* book;
	int count_str = 1;
	char symbol;
	char* text[100] = { 0 };
	char** text = (char**)malloc(20 * sizeof(char*));
	int i = 0;
	if (fopen_s(&book, "book.txt", "r"))
		perror("");
	else
	{
		while (fscanf_s(book, "%c", &symbol, 1) != EOF)
		{
			++i;
			if (symbol == '\n')
			{
				j++;
				count_str++;
				char* text[j] = (char*)malloc(i * sizeof(char));
				i = 0;
			}

		}
	}
	char** text = (char**)malloc(count_str * sizeof(char*));
	for (int i = 0; i < count_str;i++)
	{
		char* text[i] = (char*)malloc()
	}


	printf_s("%d", count_str);
	_fcloseall();
}

char split_text(char** text)
{

	int i = 0;
	int j = 0;
	char* str = { 0 };
	while (text[i] != '\0')
	{
		while (text[i] != '\n')
		{
			str[j] = text[i];
		}
	}


}
char** splitStr(char* str, char split_symbol, int memory, int* string_counter)
{
	int count = 0;
	int len = strSize(str);
	for (int i = 0; i < len; i++)
	{
		if (str[i] == split_symbol)
		{
			count++;
		}
	}
	count++;
	(*string_counter) = count;
	char** arr = (char**)malloc(sizeof(char*) * count);
	for (int i = 0; i < count; i++)
	{
		arr[i] = (char*)malloc(sizeof(char) * memory);
		/*arr[i] = (char*)malloc(sizeof(char) * lenarr[i]);*/ // ��������� ������� ���������� ������ ��� ������ ����� ������
	}
	int order = 0; // ��� �� ������-��������� str
	for (int i = 0; i < count; i++) // ������ �� ������
	{
		int j = 0; // ������ �� ������ �������� ������
		char c = NULL;
		while (c != split_symbol)
		{
			c = str[order];
			if (c == split_symbol)
			{
				arr[i][j] = '\0';
				order++;
				break;
			}
			arr[i][j] = c; // ����� ������������� ������������??
			if (order == len)
			{
				break;
			}
			j++;
			order++;
		}
	}
	return arr;
}











//char** text = (char**)malloc(20 * sizeof(char*));
/*fscanf_s(book, "%s", text);*/




//char split_str()
//{
//	
//}
//
//for (int i = 0; i != '/0'; i++)
//{
//	size++;
//}