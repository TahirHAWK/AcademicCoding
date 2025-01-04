

#include<stdio.h>

int main() {
	int a = 262;
	int *b = &a;
	int c = *b ;
	printf("a = %d\n", a);
	printf("*&a = %d\n", *&a);
	printf("b = %d\n", c);
	return 0;
}
// last studied page 334