/* #define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>


int checkIfLessZeroOrMore255(int digitBitte);

int main() {
	int pixel[4][4] = { 0 };
	printf("Enter a digit bitte: \n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			scanf("%d", &pixel[i][j]);
			pixel[i][j] = checkIfLessZeroOrMore255(pixel[i][j]);
		}
	}


	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%d ", pixel[i][j]);
		}
	}

	return 0;

}


int checkIfLessZeroOrMore255(int digitBitte) {
	if (digitBitte < 0) {
		return 0;
	}
	else if (digitBitte > 255) {
		return 255;
	}
	else {
		return digitBitte;
	}
}