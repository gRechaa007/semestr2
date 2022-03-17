#include"string.h"

int subString(char* string, char* sub)
{
	int strSize = stringSize(string);
	int subSize = stringSize(sub);
	if (subSize > strSize)
	{
		printf_s("Substring size cannot be more than string size!\n");
		return -1;
	}
	int overlap = 0;
	int count = 0;
	for (int i = 0; i < strSize; i++)
	{
		for (int j = 0; j < subSize && i + j < strSize; j++)
		{
			if (string[i + j] == sub[j])
				overlap++;
			else
			{
				overlap = 0;
				break;
			}
			if (overlap == subSize)
			{
				return i;
			}
		}
	}
	return -1;
}
int stringSize(char* string)
{
	int i = 0;
	while (string[i] != '\0')
		i++;
	return i;
}
int countSubStr(char* string, char* sub)
{
	int strSize = stringSize(string);
	int subSize = stringSize(sub);
	if (subSize > strSize)
	{
		printf_s("Substring size cannot be more than string size!\n");
		return;
	}
	int overlap = 0;
	int count = 0;
	for (int i = 0; i < strSize; i++)
	{
		overlap = 0;
		for (int j = 0; j < subSize && i + j < strSize; j++)
		{
			if (string[i + j] == sub[j])
				overlap++;
			else
			{
				break;
			}
			if (overlap == subSize)
			{
				count++;
				i += j;
			}
		}
	}
	return count;
}
//void splitStr(char* string, char sep)
//{
//	int strSize = stringSize(string);
//	int count = 0;
//	char** array = NULL;
//	for (int i = 0; i < strSize; i++)
//	{
//		if (string[i] == sep)
//			count++;
//	}
//	count++;
//	int countOfsymbols = count;
//	array = (char**)malloc(sizeof(char*) * count);
//	count = 0;
//	int j = 0;
//	for (int i = 0; i < strSize; i++)
//	{
//		count++;
//		if (string[i] == sep || string[i] == '\0')
//		{
//			if (string[i] == '\0')
//			{
//				count--;
//				array[j] = (char*)malloc(count * sizeof(char));
//			}
//			array[j] = (char*)malloc(count * sizeof(char));
//			count = 0;
//			j++;
//		}
//	}
//	// Выделение памяти закончилось.
//	int z = 0;
//	j = 0;
//	for (int i = 0; i < strSize; i++)
//	{
//		/*if (i == strSize)
//		{
//			array[j][z] = '\0';
//			break;
//		}*/
//		if (string[i] == sep || string[i] == '\0')
//		{
//			/*if (string[i] == '\0')
//			{
//				array[j][z] = '\0';
//				break;
//			}*/
//			array[j][z] = '\0';
//			printf("%d) %s", j, array[j]);
//			printf("|<-end\n");
//			j++;
//			z = 0;
//			//i++;
//			z--;
//		}
//		if (j == countOfsymbols)
//		{
//			for (;string[i] != '\0';i++)
//			{
//				array[j][z] = string[i];
//				z++;
//			}
//			break;
//		}
//		if (i == strSize)
//			break;
//		array[j][z] = string[i];
//		z++;
//	}
//	return array;
//}


char* replace(char* string, char* sub, char* new) {
	int count = countSubStr(string, sub);
	if (count == 0)
		return string;
	int sizeStr = stringSize(string);
	int sizeSub = stringSize(sub);
	int sizenew = stringSize(new);
	int Newlinesize = (sizeStr - (count * sizeSub) + (count * sizenew));
	int* entryPositions = (int*)malloc(count * sizeof(int));
	int n = 0;
	int i, j, k;
	for (i = 0; string[i] != '\0'; i++) {
		for (j = i, k = 0; sub[k] != '\0' && string[j] == sub[k]; j++, k++);
		if (sub[k] == '\0') {
			entryPositions[n] = i;
			n++;
			i += sizeSub;
		}
	}
	n = 0;
	char* Newline = (char*)malloc((Newlinesize + 1) * sizeof(char));
	for (i = 0, j = 0; i < Newlinesize; ) {
		if (j != entryPositions[n]) {
			Newline[i++] = string[j++];
		}
		else {
			j += sizeSub;
			for (int p = 0; p < sizenew; p++, i++) {
				Newline[i] = new[p];
			}
			n++;
		}
	}

	Newline[Newlinesize] = '\0';
	free(entryPositions);
	return Newline;
}

//return arr

/*for (int i = 0;i < strSize;i++)
{
	for (int j = 0;string[j + i] != sep;j++)
	{
		count++;
	}
	char* array = (char*)malloc(sizeof(char) * count);

	for (int i = 0; i < count; i++)
	{
		array[i] = string[i];
	}
	printf_s("newString = %s", array);
	i = count + 1;
	count = 0;
}*/







//	{
//		if (string[i] == symbol)
//		{
//			count++;
//		}
//	}
//
//	char** array = (char**)malloc(sizeof(char*) * count);
//
//	for (int i = 0; i < count; i++)
//	{
//		array[i] = (char*)malloc(sizeof(char) * memory);
//	}
//	int order;
//	for (int i = 0; i < count; i++) // Пробег по строке
//	{
//		int j = 0; // Пробег по номеру элемента строки
//		char c = NULL;
//		while (c != symbol)
//		{
//			c = string[order];
//			if (c == symbol)
//			{
//				array[i][j] = '\0';
//				order++;
//				break;
//			}
//			array[i][j] = c; // ложно положительное срабатывание??
//			if (order == strSize)
//			{
//				break;
//			}
//			j++;
//			order++;
//		}
//	}
//	return array;
//}

