#include<stdlib.h>
#include<stdio.h>
#include <string.h>
#include<math.h>

void function();
void checking(arr, size);

int main()
{
	function();
}

void function()
{
	int i = 0;
	char* arr = (char*)malloc(100 * sizeof(char));
	while (1)
	{
		char c = getchar();
		if (c == EOF)
		{
			break;
		}
		arr[i] = c;
		i++;
	}
	arr[i] = '\0';
	int size = strlen(arr);
	checking(arr, size);
	free(arr);
}
void checking(char* arr, int size)
{
	char* tmp = (char*)malloc(100 * sizeof(char));
	for (int i = 0; i < size; i++)
	{
		if (arr[i] >= '0' && arr[i] <= '9')
		{
			int z = i;
			int y = 0;
			while (1)
			{
				if (arr[z] >= '0' && arr[z] <= '9')
				{
					tmp[y] = arr[z];
					y++;
					z++;
				}
				else
				{
					tmp[y] = '\0';
					printf("%g ", pow(atoi(tmp), 2));
					free(tmp);
					tmp = (char*)malloc(100 * sizeof(char));
					break;
				}
			}
			i += y;
		}
	}
	free(tmp);
}