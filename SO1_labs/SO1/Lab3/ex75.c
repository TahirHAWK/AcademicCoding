#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include<math.h>

struct complexNumber {
	double realX, complexY;
};

double getComplexAbsolute(struct complexNumber z);
double getComplexPhase(struct complexNumber z);
struct complexNumber addComplex(struct complexNumber z1, struct complexNumber z2);

int main() {
	struct complexNumber z1, z2, z3;
	printf("z1 = ");
	scanf("%lf %lf", &z1.realX, &z1.complexY);
	printf("z2 = ");
	scanf("%lf %lf", &z2.realX, &z2.complexY);

	z3 = addComplex(z1, z2);

	printf("Absolute	: |z1|	  = %lf", getComplexAbsolute(z1));
	printf("\nPhase		: arg(z1) = %lf", getComplexPhase(z1));

	printf("* PI\nSum		: z1 + z2 = %lf %lf", z3.realX, z3.complexY);

	return 0;
}

double getComplexAbsolute(struct complexNumber z) {

	return sqrt(((z.realX)* (z.realX)) + ((z.complexY)* (z.complexY)));
}
double getComplexPhase(struct complexNumber z) {
	return tanh(z.complexY/z.realX);
}
struct complexNumber addComplex(struct complexNumber z1, struct complexNumber z2) {
	struct complexNumber z3 = { (z1.realX+z2.realX) , (z1.complexY + z2.complexY) };
	return z3;
}