//#include <stdio.h>
//#include <stdlib.h>
//#include<string.h>
//#define SIZE 100
//
////int* findStr(char* str1, char* str2, int* count);
//int findStr(char* str1, char* str2);
//int strSize(char* string);
//char** splitStr(char* str, char split_symbol, int memory, int* string_counter);
//
//
//int main()
//{
//	char str1[SIZE];
//	char str2[SIZE];
//	//char* str1 = "Looo oox";
//	//char* str2 = "ox";
//	//printf("%d", strSize(str2));
//
//	printf("Input string: ");
//	gets(str1);
//	printf("Input substring: ");
//	gets(str2);
//
//	int str1_size = strSize(str1);
//	int str2_size = strSize(str2);
//
//	if (str1_size < str2_size)
//	{
//		printf("Error. String must be longer than substring.\n");
//		exit(1);
//	}
//
//	int first_index = findStr(str1, str2);
//	printf("First entry: %d\n", first_index);
//
//	int substring_number = countSubstring(str1, str2);
//	printf("Count of substring' entries: %d\n", substring_number);
//
//	int* string_counter = -1;
//	char** arr = splitStr(str1, ' ', SIZE, &string_counter);
//	for (int i = 0; i < string_counter; i++)
//	{
//		printf("%d string = %s\n", i + 1, arr[i]);
//		free(arr[i]);
//	}
//	free(arr);
//
//	return 0;
//}
//
//int strSize(char* str)
//{
//	int i = 0;
//	while (str[i] != '\0')
//	{
//		i++;
//	}
//	return i;
//}

//int* findStr(char* str1, char* str2, int* count)
//{
// (*count) = 0;
// int i, j, index = -1;
// int* entry = (int*)malloc(sizeof(int));
// for (i = 0; str1[i] != '\0'; i++)
// {
// for (j = 0; str2[j] != '\0' && str1[i + j] == str2[j]; j++);
// {
// if (j > 0 && str2[j] == '\0')
// {
// //if (index == -1) index = i;
// entry[(*count)] = i;
// (*count)++;
// entry = (int*)realloc(entry, ((*count) + 1) * sizeof(int));
// }
// }
// }
// return entry;
//}
//
//char** splitStr(char* str, char split_symbol, int memory, int* string_counter)
//{
//	int count = 0;
//	int order = 0;
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
//	//int* lenarr = (int*)malloc(sizeof(int) * count);
//	//int z = 0;
//	//for (int i = 0; i < len; i++)
//	//{
//	// order++;
//	// if (str[i] == split_symbol)
//	// {
//	// //order--;
//	// lenarr[z] = order;
//	// order = 0;
//	// z++;
//	// }
//	// /*if (str[i] == '\0')
//	// {
//	// lenarr[z] = order;
//	// order = 0;
//	// break;
//	// }*/
//	//}
//	char** arr = (char**)malloc(sizeof(char*) * count);
//	for (int i = 0; i < count; i++)
//	{
//		arr[i] = (char*)malloc(sizeof(char) * memory);
//		/*arr[i] = (char*)malloc(sizeof(char) * lenarr[i]);*/ // Выделение нужного количества памяти под каждое слово строки
//	}
//	order = 0; // Шаг по строке-аргументу str
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
//int findStr(char* str1, char* str2)
//{
//	int index = -1;
//	int count = 0;
//	int len1 = strSize(str1);
//	int len2 = strSize(str2);
//
//	for (int i = 0; i < len1; i++)
//	{
//		if (str2[0] == str1[i])
//		{
//			index = i;
//			int k = i;
//			for (int j = 0; j < len2; j++, k++)
//			{
//				if (str1[k] == str2[j])
//				{
//					count++;
//					if (count == len2)
//					{
//						return index;
//					}
//				}
//				else
//				{
//					count = 0;
//					index = -1;
//					break;
//				}
//			}
//		}
//	}
//	return index;
//}
//
//int countSubstring(char* str1, char* str2)
//{
//	int index = -1;
//	int count = 0;
//	int ccount = 0;
//	int len1 = strSize(str1);
//	int len2 = strSize(str2);
//
//	for (int i = 0; i < len1; i++)
//	{
//		if (str2[0] == str1[i])
//		{
//			index = i;
//			int k = i;
//			for (int j = 0; j < len2; j++, k++)
//			{
//				if (str1[k] == str2[j])
//				{
//					count++;
//					if (count == len2)
//					{
//						count = 0;
//						ccount++;
//					}
//				}
//				else
//				{
//					count = 0;
//					index = -1;
//					break;
//				}
//			}
//		}
//	}
//	return ccount;
//}