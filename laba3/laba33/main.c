//#include <stdio.h>
//#include <stdlib.h>
//#define SIZE 100
//
//void fill_str(char str1[]);
//int* find_str(char str1[], char str2[], int* count);
//void print_str(int* index, int* count);
//
//int main()
//{
//	char str1[SIZE];
//	char str2[SIZE];
//
//	int count = 0;
//
//	printf("Input string: ");
//	fill_str(str1);
//
//	printf("Input substring: ");
//	fill_str(str2); // вызываем функцию заполнения для второго массива(подстрока).
//
//	print_str(find_str(str1, str2, &count), &count); // функция вывода с аргументом возвращаемого значения из функции сравнения строк.
//	printf("\nCount of substrs: %d", count);
//	getchar();
//	return 0;
//}
//
//void fill_str(char str1[]) // заполнение массива.
//{
//	gets(str1); // получаем ввод пользователя для заполнения массива
//}
//
//int* find_str(char str1[], char str2[], int* count)
//{
//	(*count) = 0;
//	int i, j, index = -1;
//	int* idx = (int*)malloc(sizeof(int));
//	for (i = 0; str1[i] != '\0'; i++)
//	{
//		for (j = 0; str2[j] != '\0' && str1[i + j] == str2[j]; j++);
//		{
//			if (j > 0 && str2[j] == '\0')
//			{
//				//if (index == -1) index = i;
//				idx[(*count)] = i;
//				(*count)++;
//				idx = (int*)realloc(idx, ((*count) + 1) * sizeof(int));
//			}
//		}
//	}
//	return idx;
//} // возвращаем индекс } void print_str(int index) // функция вывода. { index != -1 ? printf("str1 in str2, entry i is: %d", index) : printf("str1 not in str2"); }
//
//void print_str(int* index, int* count)
//{
//	for (int i = 0; i < (*count); i++)
//	{
//		printf("idx[%d] = %d\n", i, index[i]);
//	}
//	//index != -1 ? printf("str1 in str2, entry index is: %d", index) : printf("str1 not in str2");
//}
//
//
//
//
////#include<stdio.h>
////#include<stdlib.h>
////
////int my_strlen(char* str)
////{
////	int i = 0;
////	while (str[i] != '\0')
////		i++;
////	return i;
////}
////
////int my_strstr(char* str, char* substr)
////{
////	int sizeStr = my_strlen(str);
////	int sizeSubstr = my_strlen(substr);
////	int i = 0;
////
////	while (i < sizeStr)
////	{
////		if (str[i] == substr[0])
////		{
////			int isSubstr = 1;
////			for (int j = 0; j < sizeSubstr; j++)
////			{
////				if (str[i + j] != substr[j])
////					isSubstr = 0;
////			}
////			if (isSubstr)
////				return i;
////		}
////		++i;
////	}
////	return -1;
////
////}
