/*

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	int matrix[3][3] = { 0 };
	int vector[3] = { 0 };
	int result[3] = { 0 };


	printf("shei vai shei, Input bitte:");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}
	printf("shei vai shei, Vector Input bitte:");
	for (int i = 0; i < 3; i++) {
			scanf("%d", &vector[i]);
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			result[i] += matrix[i][j] * vector[j];
		}
	}

	for (int j = 0; j < 3; j++) {
		printf("%d \n", result[j]);
	}


	return 0;
}
*/