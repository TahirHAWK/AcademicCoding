/*

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
*/

// exercise 36
//int throwDice();
//
//int main(void)
//{
//	int randomNumber;
//	int roll[100];
//	int total = 0;
//	int occurance[6] = { 0 };
//
//	srand(time(NULL)); // I n i t i a l i z e random number g e n e r a t o r
//	for (int i = 0; i < 100; i++) {
//		roll[i] = throwDice();
//		total = total + roll[i];
//	}
//
//	for (int i = 0; i < 100; i++) {
//		printf("%d ", roll[i]);
//		if ((i + 1) % 25 == 0) {
//			printf("\n");
//		}
//	}
//
//	double avarage = total / 100.0;
//	printf("\n Avarage = %0.1lf", avarage);
//	return 0;
//}
//
//int throwDice() {
//	int max = 6;
//	int min = 1;
//	return (rand() % (max - min + 1)) + min;
//}

// exercise 44

/*int throwDice();
int countOccurance(int i, int occurance[]);

int main(void)
{
	int roll[100];
	int total = 0;
	int occurance[6] = { 0 };

	srand(time(NULL)); // I n i t i a l i z e random number g e n e r a t o r
	for (int i = 0; i < 100; i++) {
		roll[i] = throwDice();
		countOccurance(roll[i], occurance);
	}



	/*for (int i = 0; i < 6; i++) {
		printf("%d ", occurance[i]);
	}

	return 0;
}

int throwDice() {
	int max = 6;
	int min = 1;
	return (rand() % (max - min + 1)) + min;
}

int countOccurance(int i, int occurance[]) {
	switch (i) {
	case 1:
		occurance[0] += 1;
		break;
	case 2:
		occurance[1] += 1;
		break;
	case 3:
		occurance[2] += 1;
		break;
	case 4:
		occurance[3] += 1;
		break;
	case 5:
		occurance[4] += 1;
		break;
	case 6:
		occurance[5] += 1;
		break;
	}
}

*/