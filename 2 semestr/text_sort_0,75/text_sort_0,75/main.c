#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<locale.h>



int comp(const void* arg1, const void* arg2);

int main()
{
	setlocale(0, "rus");
	FILE* book;
	int count_str = 0;
	char symbol;
	int* num_str = NULL;
	int strSize = 0;
	if (fopen_s(&book, "book.txt", "r+"))
		perror("");
	else
	{
		while (fscanf_s(book, "%c", &symbol, 1) != EOF)
		{
			++strSize;
			if (symbol == '\n')
			{
				count_str++;
				int* tmp = (int*)realloc(num_str, strSize * sizeof(int));
				num_str = tmp;
				num_str[count_str - 1] = strSize;

				strSize = 0;
			}

		}
	}
	rewind(book);

	char** text = (char**)malloc(count_str * sizeof(char*));
	for (int i = 0; i < count_str; i++)
	{
		text[i] = (char*)calloc(num_str[i], sizeof(char*));
	}

	for (int i = 0; i < count_str; i++)
	{
		for (int j = 0; j < num_str[i];j++)
		{
			text[i][j] = fgetc(book);
		}
	}

	qsort(text, count_str, sizeof(char*), comp);

	/*printf_s("%d", count_str);*/
	fprintf(book, "\n");
	fprintf(book, "\n");

	for (int i = 0; i < num_str[i]; ++i) {
		for (int j = 0; text[i][j] != '\n'; ++j) {
			fprintf(book, "%c", text[i][j]);
		}
		fprintf(book, "\n");
	}
	_fcloseall();
	free(num_str);

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

int comp(const void* arg1, const void* arg2)
{
	const char** tmpStr1 = (char**)arg1;
	const char** tmpStr2 = (char**)arg2;

	return((strlen(*tmpStr1)) - (strlen(*tmpStr2)));

}


//char** splitStr(char* str, char split_symbol, int memory, int* string_counter)
//{
//	int count = 0;
//	int len = strSize(str);
//	for (int i = 0; i < len; i++)
//	{
//		if (str[i] == split_symbol)
//		{
//			count++;
//		}
//	}
//	count++;
//	(*string_counter) = count;
//	char** arr = (char**)malloc(sizeof(char*) * count);
//	for (int i = 0; i < count; i++)
//	{
//		arr[i] = (char*)malloc(sizeof(char) * memory);
//		/*arr[i] = (char*)malloc(sizeof(char) * lenarr[i]);*/ // Выделение нужного количества памяти под каждое слово строки
//	}
//	int order = 0; // Шаг по строке-аргументу str
//	for (int i = 0; i < count; i++) // Пробег по строке
//	{
//		int j = 0; // Пробег по номеру элемента строки
//		char c = NULL;
//		while (c != split_symbol)
//		{
//			c = str[order];
//			if (c == split_symbol)
//			{
//				arr[i][j] = '\0';
//				order++;
//				break;
//			}
//			arr[i][j] = c; // ложно положительное срабатывание??
//			if (order == len)
//			{
//				break;
//			}
//			j++;
//			order++;
//		}
//	}
//	return arr;
//}
//
//
//
//
//
//
//
//



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