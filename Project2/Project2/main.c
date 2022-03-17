#include "MyString.h"
#include <stdio.h>
int main()
{
	char asd[123] = "asdasdad";
	
	int size = my_strlen(asd);
	char str[255];
	char subStr[255];
	gets_s(str, 255);
	gets_s(subStr, 255);
	int x = my_strstr(str, subStr);
	//scanf_s(255, "%s", str);

}