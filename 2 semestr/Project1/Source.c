#include<stdlib.h>
#include<stdio.h>

#include<stdlib.h>
#include<stdio.h>

#define SIZE 100;

void function();
void check(arr, len);
int main()
{
	function();


}

void check(char* arr, int* len)
{
	char* tmp = (char*)malloc(100 * sizeof(char));
	for (int i = 0; i < len; i++)
	{
		if (arr[i] >= '0' && arr[i] <= '9')
		{
			int z = i;
			int y = 0;
			while (1)
			{
				if (arr[z] >= '0' && arr[z] <= '9')
				{
					tmp[y] = (int)(arr[z]);
					y++;
					z++;
				}
				else
				{
					/*tmp[y] = '\0';*/
					printf("%d ", pow(atoi(tmp), 2));
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
int arrSize(char* arr)
{
	int i = 0;
	while (arr[i] != '\0')
		i++;
	return i;
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
	int len = arrSize(arr);
	check(arr, len);
	free(arr);
}