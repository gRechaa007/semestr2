#include <stdio.h>

int main()
{
	int mass[10] = { 0 };
	for (int i = 0; i < 10;i++)
	{
		scanf_s("%d", &mass[i]);
	}
	for (int i = 0; i <= 10 ;i++)
	{
		if (mass[i] > 0)
		{
			printf("%d ", mass[i]);
		}
	}
	system("pause");	
}