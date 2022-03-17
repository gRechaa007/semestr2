#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

#define SIZEP 10

void power(char* pass, int ch);

int main()
{
	char* pass = (char*)malloc(SIZEP * sizeof(char));
	int i = 0;
	int ch = 0;
	while (1)
	{
		char c = _getch();
		if (c == VK_RETURN)
		{
			break;
		}
		else if (c == 8)
		{
			if (i > 0)
			{
				i--;
				printf_s("\b \b");
			}
		}
		else
		{
			printf_s("*");
			pass[i] = c;
			i++;
		}
	}
	pass[i] = '\0';
	power(pass, ch);
	printf("\n\n");

	printf("%s", pass);
}

int stringSize(char* pass)
{
	int i = 0;
	while (pass[i] != '\0')
		i++;
	return i;
}

void power(char* pass, int ch)
{
	for (int i = 0; i < SIZEP; i++)
	{
		if (pass[i] >= '0' && pass[i] <= '9')
		{
			ch++;
			if (ch == 1)
				break;
		}
		if (ch == 1)
			break;
	}
	if (ch == 0)
	{
		printf_s("\nBad password! Add numbers for reliability...");
		ch = 1;
	}
		
	for (int j = 0; j < SIZEP; j++)
	{
		if (pass[j] >= 'A' && pass[j] <= 'Z')
		{
			ch++;
			if (ch == 2)
				break;
		}
		if (ch == 2)
			break;
	}
	if (ch == 1)
	{
		printf_s("\nBad password! Add capital letters for reliability...");
		ch = 2;
	}

	for (int k = 0; k < SIZEP; k++)
	{
		if (pass[k] >= '!' && pass[k] <= '/')
		{
			ch++;
			if (ch == 3)
				break;
		}
		if (ch == 3)
			break;
	}
	if (ch == 2)
	{
		printf_s("\nBad password! Add special symbols for reliability...");
	}

	for (int j = 0; j < SIZEP; j++)
	{
		if (pass[j] >= 'a' && pass[j] <= 'z')
		{
			ch++;
			if (ch == 4)
				break;
		}
		if (ch == 4)
			break;
	}
	if (ch == 3)
	{
		printf_s("\nBad password! Add small letters for reliability...");
		ch = 2;
	}
	
	int s = stringSize(pass);
	if (s <= 7)
	
	printf_s("\nSmall long...");
		
	if (s >= 7 && s <= 13 )
		printf_s("\nNormal long...");


	if(ch == 4 && s > 13)
	printf_s("\nGood password! ");
}
