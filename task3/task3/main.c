# include <stdio.h>
int main() 
{
	int numb[10] = { 0,3,5,23,6,7,8,8,9,4 };
	for (int i = 0; i < 10;i++)
	{
		printf("%d", numb[i]);
	}
	printf("\n");
	char word[7] = { 'k','o','s','h','k','a' };
	for (int j = 0; j < 7; j++)
	{
		printf("%c ", word[j]);
	}
	system("pause");
	
}