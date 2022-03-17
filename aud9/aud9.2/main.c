#include<stdio.h>

struct complexrNum {
	double real;
	double im;

}typedef ComplexNum;

int main()
{
	char operation;
	ComplexNum num1, num2, lResult, Result;
	scanf_s("(%lf,%lf) %c (%lf,%lf)", &num1.real, &num1.im, &operation, 1, &num2.real, &num2.im);

    switch (operation) {
    case '+':
        Result.real = num1.real + num2.real;
        Result.im = num1.im + num2.im;
        break;
    case '-':
        Result.real = num1.real - num2.real;
        Result.im = num1.im - num2.im;
        break;
    case '*':
        Result.real = num1.real * num2.real - num1.im * num1.im;
        Result.im = num1.real * num2.im + num2.real * num1.im;
        break;
    default:
        printf_s("ERROR");
        return 1;
    }
    printf_s("%g %g", Result.real, Result.im);
        return 0;
}