

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

char* substring(char *arr, int m, int n);

int main() {

	char s[] = "The Globe Sessions";
	int m, n, bitte[3];
	size_t len =0;
	printf("Enter bitte: ");
	scanf("%d,%d,%d", &bitte[0], &bitte[1], &bitte[2]);
	printf("\n %d %d %d" , bitte[0], bitte[1], bitte[2]);
	//printf("Original String: \"%s\"", s);
	//printf("Enter indices of substring (formatted \"first:last\"): ");
	//scanf("%d:%d", &m, &n);
	
	return 0;
}

char* substring(char* arr, int m, int n) {

}