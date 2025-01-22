/*
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int main() {
	char myString[100] = { 0 };
	int count = 0;
	printf("write what your heart desires: ");
	fgets(myString, 99, stdin);
	
	for (int i = 0; i < strlen(myString); i++) 
	{
		if (myString[i] == 'a' || myString[i] == 'A') {
			count++;
		}
	}

	printf("a is printed %d times, shei vai shei", count);
	return 0;
}

*/