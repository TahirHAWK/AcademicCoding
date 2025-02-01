// my code 19.2 mathematical 2D vectors page 58
/*

#define _CRT_SECURE_NO_WARNINGS
#define DIM 2
#include<math.h>
#include<stdio.h>

void printVector2D(struct vector vector[DIM]);
double vectorLength(struct vector vector[]);
void scaleVector2D(struct vector *vector);
double dotProduct2D(struct vector vector[DIM]);

struct vector {
	double x, y;
};


int main() {
	struct vector vectors[DIM] = {{3.0, 4.0} , {-2.0, 6.0}};
	printVector2D(&vectors);
	return 0;
}


void printVector2D(struct vector vectors[DIM]) {
	printf("Vectors: \n"
		"a1 = (%.1lf, %.1lf)\n"
		"a2 = (%.1lf, %.1lf)\n\n"
		"Vector length:\n"
		"|a1| = %.1lf\n"
		, vectors[0].x, vectors[0].y, vectors[1].x, vectors[1].y, vectorLength(vectors)
	);
	scaleVector2D(&vectors[1]);
	printf(
		"Scale a2 with 0.5:\n"
		"a2 = (%.1lf, %.1lf)\n"
		"Dot product:\n"
		"<a1, a2> = %.1lf",  vectors[1].x, vectors[1].y, dotProduct2D(vectors)
	);
}

double vectorLength(struct vector vector[]) {
	return sqrt((vector[0].x) * (vector[0].x) + (vector[0].y) * (vector[0].y));
}

void scaleVector2D(struct vector *vector) {
	vector->x = vector->x * 0.5;
	vector->y = vector->y * 0.5;
}

double dotProduct2D(struct vector vector[DIM]) {
	return vector[0].x * vector[1].x + vector[0].y * vector[1].y;
}
*/



// chatgpt code
/*
#define _CRT_SECURE_NO_WARNINGS
#define DIM 2
#include <math.h>
#include <stdio.h>

// Structure Definition
struct vector {
    double x, y;
};

// Function Prototypes
void printVector2D(const struct vector vectors[DIM]);
double vectorLength(struct vector vector);
void scaleVector2D(struct vector* vector);
double dotProduct2D(const struct vector vectors[DIM]);

int main() {
    struct vector vectors[DIM] = { {3.0, 4.0}, {-2.0, 6.0} };

    printVector2D(vectors);

    return 0;
}

// Function Definitions

void printVector2D(const struct vector vectors[DIM]) {
      // Copy a2 before scaling
    scaleVector2D(&vectors[1]); // Scale a2 with 0.5

    printf("V e c t o r s :\n"
        "a1 = ( %.1f , %.1f )\n"
        "a2 = ( %.1f , %.1f )\n\n"
        "V e c t o r l e n g t h :\n"
        "| a1 | = %.1f\n"
        "S c a l e a2 w i t h 0 . 5 :\n"
        "a2 = ( %.1f , %.1f )\n"
        "D o t p r o d u c t :\n"
        "< a1 , a2 > = %.1f\n",
        vectors[0].x, vectors[0].y,
        vectors[1].x, vectors[1].y,
        vectorLength(vectors[0]),
        vectors[1].x, vectors[1].y,
        dotProduct2D(vectors));
}

double vectorLength(struct vector vector) {
    return sqrt((vector.x * vector.x) + (vector.y * vector.y));
}

void scaleVector2D(struct vector* vector) {
    vector->x = vector->x * 0.5;
    vector->y = vector->y * 0.5;
}

double dotProduct2D(const struct vector vectors[DIM]) {
    return vectors[0].x * vectors[1].x + vectors[0].y * vectors[1].y;
}
*/

// my code 19.3 prime numbers page 59

/*
#define _CRT_SECURE_NO_WARNINGS
#include<ctype.h>
#include<stdio.h>

enum boolean isEven(int number);
enum boolean isPrimeNumber(int k);
void clearKeyboardBuffer();

enum boolean {
    FALSE,
    TRUE
};

enum boolean isEven(int number) {
    if (number % 2 == 0) {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

enum boolean isPrimeNumber(int k) {
    if (k <= 1) {
        return FALSE;
    } else if (isEven(k) && k >= 4) {
        return FALSE;
    }

    for (int i = 1; i <= k; i=i+2) {
        if (i >= 3 && i < (k / 2)) {
            if (k % i == 0) {
                return FALSE;
            }
        }
            
    }
    return TRUE;

    
}

int main() {
    int rangeNumber = 0, count = 0;
    while (1) {
        printf("Enter maximum number to test: \n");
        scanf("%d", &rangeNumber);
        if (rangeNumber < 0) {

            clearKeyboardBuffer();
            printf("Invalid input, must be positive integer. Retry: \n");
        }
        else {
            break;
        }
    }

    printf("Prime numbers in [ 1, %d ]\n", rangeNumber);
    for (int i = 1; i <= rangeNumber; i++) {
        if (isPrimeNumber(i)) {
            count++;
            printf(" %d ", i);
            if (count % 10 == 0) {
                printf("\n");
            }
        }
    }

    printf("\nThere are %d prime numbers in [ 1, %d ].\n", count, rangeNumber);

    return 0;

}

void clearKeyboardBuffer() {
    while (getchar() != '\n');  // Read until the newline character
}
*/


// chapter 20 page 61 complex number and euclidean algorithm
#define _CRT_SECURE_NO_WARNINGS
#include<math.h>
#include<stdio.h>


double absolute(struct Complex complexNumber);
struct Complex multiply(struct Complex cN1, struct Complex cN2);
struct Complex add(struct Complex cN1, struct Complex cN2);

struct Complex {
    double real, imag;
};

int main() {
    struct Complex a = { 3.0, 4.0 }, b = {2.0, -1.0}, sum = add(a, b), mul = multiply(a, b);
    printf("Input data: \n");
    printf("z1 = %lf + %lfj\n"
    "z2 = %lf + %lfj\n", a.real, a.imag, b.real, b.imag);
    printf("Absolute values: \n"
    "|z1| = %lf\n"
    "|z2| = %lf\n", absolute(a), absolute(b));
    printf("Mathematical operations:\n"
        "z1+z2 = %lf + %lfj\n"
        "z1*z2 = %lf + %lfj\n", sum.real, sum.imag, mul.real, mul.imag

    );
    return 0;
}

double absolute(struct Complex complexNumber) {
    return sqrt(((complexNumber.real * complexNumber.real) + (complexNumber.imag * complexNumber.imag)));
}

struct Complex add(struct Complex cN1, struct Complex cN2) {
    struct Complex cnSum;
    cnSum.real = cN1.real + cN2.real;
    cnSum.imag = cN1.imag + cN2.imag;
    return cnSum;
}

struct Complex multiply(struct Complex cN1, struct Complex cN2) {
    struct Complex cnMul;
    cnMul.real = cN1.real * cN2.real - cN1.imag * cN2.imag;
    cnMul.imag = cN1.real * cN2.imag + cN2.real * cN1.imag;
    return cnMul;
}

