#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int isEqualArray(int arr1[5], int arr2[5]);

int main() {
	int a[5], b[5], c[5] = { 0 };
	printf("a: ");
	for (int i = 0; i < 5; i++) {
		scanf("%d", &a);
	}
	printf("b: ");
	for (int i = 0; i < 5; i++) {
		scanf("%d", &b);
	}
	printf("c: ");
	for (int i = 0; i < 5; i++) {
		scanf("%d", &c);
	}

	printf("Compare arrays value by value: \n"
			"Is a same as b?: %s\n"
			"Is a same as c?: %s\n"
			"Is b same as c?: %s\n"
		, isEqualArray(a,  b)? "true": "false", 
		  isEqualArray(a, c) ? "true" : "false", 
		  isEqualArray(b, c) ? "true" : "false"
		
		);

}



int isEqualArray(int arr1[5], int arr2[5]) {

	for (int i = 0; i < 5; i++) {
		if (arr1[i] != arr2[i]) {
			
			return 0;
		}
	}
	return 1;
}