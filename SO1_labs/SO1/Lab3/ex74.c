/*

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int scalarProduct(struct X v1, struct X v2);

// define a structure
struct X {
	int x, y, z;
};

int main() {
	struct X v1, v2, v3;
	printf("v1 = ");
	scanf("%d %d %d", &v1.x, &v1.y, &v1.z);
	printf("\nv2 = ");
	scanf("%d %d %d", &v2.x, &v2.y, &v2.z);
	printf("\nv3 = ");
	scanf("%d %d %d", &v3.x, &v3.y, &v3.z);

	printf("Vectors a, b are orthogonal\\index{Vector!Orthogonal} for a * b = 0:\n");
	printf("<v1, v2> = %d\n", scalarProduct(v1, v2));
	printf("<v1, v3> = %d\n", scalarProduct(v1, v3));
	printf("<v2, v3> = %d\n", scalarProduct(v2, v3));
	return 0;
}

int scalarProduct(struct X v1, struct X v2) {

	return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}
*/