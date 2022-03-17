#include <stdlib.h>
#include <stdio.h>

 int global_counter = 0;

int numberTransition(int n, int i, int a)
{

	global_counter++;


	if (a == 1)
	{
		if (i <= n)
		{
			//global_counter++;
			numberTransition(n, i + 1, 8);
			numberTransition(n, i + 1, 6);

		}
	}
	else if (a == 2)
	{
		if (i <= n)
		{
			//global_counter++;
			numberTransition(n, i + 1, 7);
			numberTransition(n, i + 1, 9);
		}
	}
	else if (a == 3)
	{
		if (i <= n)
		{
			//global_counter++;
			numberTransition(n, i + 1, 4);
			numberTransition(n, i + 1, 8);
		}
	}
	else if (a == 4)
	{
		if (i <= n)
		{
			//global_counter++;
			numberTransition(n, i + 1, 3);
			numberTransition(n, i + 1, 9);
			numberTransition(n, i + 1, 0);
		}
	}
	else if (a == 6)
	{
		if (i <= n)
		{
			//global_counter++;
			numberTransition(n, i + 1, 1);
			numberTransition(n, i + 1, 7);
			numberTransition(n, i + 1, 0);
		}
	}
	else if (a == 7)
	{
		if (i <= n)
		{
			//global_counter++;
			numberTransition(n, i + 1, 2);
			numberTransition(n, i + 1, 6);
		}
	}
	else if (a == 8)
	{

		if (i == 1)
			return;
		if (i <= n)
		{
			//global_counter++;
			numberTransition(n, i + 1, 1);
			numberTransition(n, i + 1, 3);
		}
	}
	else if (a == 9)
	{
		if (i <= n)
		{
			//global_counter++;
			numberTransition(n, i + 1, 4);
			numberTransition(n, i + 1, 2);
		}
	}
	else if (a == 0)
	{

		if (i == 1)
			return;
		if (i <= n)
		{
			//global_counter++;
			numberTransition(n, i + 1, 4);
			numberTransition(n, i + 1, 6);
		}
	}
}

int main()
{
	int local_counter = 0;
	int i = 1;
	int mass[9] = { 1, 2, 3, 4, 6, 7, 8, 9, 0 };
	int n = 0;
	printf_s("Enter the long of t.number:...  ");
	scanf_s("%d", &n);
	for (int j = 0; j < 9;j++)
	{
		int a = mass[j];
		int funksh = numberTransition(n, i, a);
		local_counter += global_counter - 1;
		global_counter = 0;
	}

	printf_s("\n%d", local_counter);

}


/*

1 --> 2: 6 и 8
2 --> 2: 7 и 9
3 --> 2: 4 и 8
4 --> 3: 3 и 9 и 0
5 --> 0:
6 --> 3: 1 и 7 и 0
7 --> 2: 2 и 6
8 --> 2: 1 и 3
9 --> 2: 4 и 2
0 --> 2: 4 и 6
вроде
1 2 3
4 5 6
7 8 9
  0


*/