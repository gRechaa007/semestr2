//#include <stdio.h>
//#include <stdlib.h>
//int main()
//{
//	printf_s("Enter lines and cols: ");
//	int line;
//	int cols;
//	scanf_s("%d %d", &line, &cols);
//	char** arr = (char**)malloc(line * sizeof(char*));
//	for (int i = 0;i < line; i++)
//	{
//		arr[i] = (char*)malloc((cols + 1) * sizeof(char));
//		gets_s(arr[i],cols);
//	}
//	for (int i = 1; i < line; i++)
//	{
//		printf_s("%s(len = %d) ", arr[i], strlen(arr[i]));
//	}
//	for (int i = 0; i < cols;i++)
//	{
//		
//		free(arr);
//	}
//	
//	return 0;
//}
//
//#include <stdio.h>
//#include <stdlib.h>
//#include<string.h>
//int main(int argc, char** argv)
//{
//	printf_s("Enter lines and cols: ");
//	int line = atoi(argv[1]);
//	int cols = atoi(argv[2]);
//	char** arr = (char**)malloc(line * sizeof(char*));
//	for (int i = 0;i < line; i++)
//	{
//		arr[i] = (char*)malloc((cols + 1) * sizeof(char));
//		gets_s(arr[i], cols);
//	}
//	for (int i = 1; i < line; i++)
//	{
//		printf_s("%s(len = %d) ", arr[i], strlen(arr[i]));
//	}
//	for (int i = 0; i < cols;i++)
//	{
//		free(arr[i]);
//	}
//	free(arr);
//	return 0;
//}
//
