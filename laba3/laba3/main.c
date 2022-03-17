#include "string.h"


int main()
{
	//char str[100] = { '0' };
	//char sub[100] = { '0' };
	char separat = 0;
	printf_s("Enter sring and substring:\n");
	//scanf("%s %s", str, sub);
	const char* str = "111123456";
	const char* sub_str = "11";
	const char* replace_str = "1";
	int ret;
	int operation;
	printf_s("Enter operation:\n"
		"1) find\n"
		"2) count\n"
		"3) split\n"
		"4) replace\n");
	scanf_s("%d", &operation);
	switch (operation) {
	case 1:
		ret = (str, "str123");
		printf("Index: %d\n", ret);
		break;
	case 2:
		ret = countStr(str, "str");
		printf("%s count: %d\n", "str", ret);
		break;
	case 3:
		ret = replace(str, sub_str, replace_str);
		printf_s("Replace string: %s\n", ret);
		free(ret);
		break;
	case 4:
		printf_s("No done");
		break;
	default:
		printf_s("ERROR: unknown operation\nEXIT WITH ERROR CODE 1");
		return 1;
	}
}
	//char* substr = "text to split";
	////char c = ' ';
	//char** mass = splitStr(substr, ' ');
	//int count = 0;
	//for (int i = 0; i < stringSize(substr); i++)
	//{
	//	if (substr[i] == ' ')
	//		count++;
	//}
	//count++;
	//for (int i = 0; i < count; i++)
	//{
	//	printf("%d) %s\n", i, mass[i]);
	//}
	//return 0;
	//printf("First index substring = %d", subString(str, sub));
	//printf("\n");
	////printf("Count substrings = %d", countSubStr(str, sub));
	//printf("\n");
	////printf("new strings: = % s", splitStr(str, '7'));
	//printf("\n");





	//int numb;
	//printf_s("Choose operation:\n 1) Find substring\n2)...\n3)...\n 4)...\n");
	//scanf_s("%d\n", &numb);
	//switch (numb)
	//{
	//case '1':
	//	printf_s("Enter sring and substring:\n");
	//	scanf("%s %s", str, sub);

	//	printf("%d", subString(str, sub));
	//	break;
	//case '2':
	//	printf("%d", countSubStr(str, sub));

	//	break;
	//case '3':

	//	break;
	//case '4':

	//	break;

	//}

//}