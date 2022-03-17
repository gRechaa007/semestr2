#include<stdio.h>
int GetFibNum(int num)
{
	if (num == 1||num ==0)
		return 1;
	else
	return GetFibNum(num -1) + GetFibNum(num -2);
}
int main()
{
	int x = GetFibNum(4);
	printf_s("%d\n", x);
	int fibNum[10];
	fibNum[0] = 1;
	fibNum[1] = 1;
	}