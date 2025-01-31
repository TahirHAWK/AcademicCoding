#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

char* substring(char* arr, int m, int n);

int main() {
	char* s = NULL;
	size_t len = 0;

	printf("Original String: \"");
	getline(&s, &len, stdin);
	printf("\"\n");

	printf(" %s", s);
	return 0;
}

char* substring(char* arr, int m, int n) {

}