#define _CRT_NO_DEPRECATE
#include<stdio.h>

int main(void)
{
	int yearOfBirth, a , b , c, d ,e;

	printf_s("Enter your Birth year : ");
	scanf_s("%d", & yearOfBirth);

	a = yearOfBirth  % 10;
	yearOfBirth = yearOfBirth / 10;

	b = yearOfBirth % 100;
	yearOfBirth = yearOfBirth / 100;

	c = yearOfBirth % 1000;
	yearOfBirth = yearOfBirth / 1000;


	d= yearOfBirth % 1000;

	e = a + b + c + d;

	printf("The digit sum of: %d+%d+%d+%d=%d", a, b, c, d, e);

	getchar;
	return 0;

}