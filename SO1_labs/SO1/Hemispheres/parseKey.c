/*
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int main() {
	char stringInput[100] = {'a'};
	printf("Enter input as key=value: ");
	fgets(stringInput, 100, stdin);
	
	printf("Key: ");
	for (int i = 0; i < strlen(stringInput); i++) {
		if (stringInput[i] == '=') {
			printf("\nvalue: ");
			continue;
		}
		printf("%c", stringInput[i]);
	}

	return 0;
}

*/