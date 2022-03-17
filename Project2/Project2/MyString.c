#include "MyString.h"
#include <stdlib.h>

int my_strlen(char* str)
{
	int i = 0;
	while (str[i] != '\0')
		i++;
	return i;
}

int my_strstr(char* str, char* substr)
{
	int sizeStr = my_strlen(str);
	int sizeSubstr = my_strlen(substr);
	int i = 0;
	
	while (i < sizeStr)
	{
		if (str[i] == substr[0])
		{
			int isSubstr = 1;
			for (int j = 0; j < sizeSubstr; j++)
			{
				if (str[i + j] != substr[j])
					isSubstr = 0;
			}
			if (isSubstr)
				return i;
		}
		++i;
	}
	return -1;

}
