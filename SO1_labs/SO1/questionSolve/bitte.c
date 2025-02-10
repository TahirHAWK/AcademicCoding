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
/*
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
*/

/* 20.3 divisors and euclidean algorithm , page 62*/
/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void sortDescending(int* a, int* b)
{
    if (*b >= *a)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
}

int greatestCommonDivisor(int m, int n)
{
   while (1)
    {
        sortDescending(&m, &n);
        int r = (m % n);
        if (r == 0)
        {
            return n;
        }
        else
        {
            m = n;
            n = r;
        }
    }
}

int getNumberOfDivisors(int num)
{
    int count = 0;

    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0)
        {
            count++;
        }
    }

    return count;
}

int* newArrayOfDivisors(int x)
{
    int size = getNumberOfDivisors(x);
    int* arr = (int*)malloc(size * sizeof(int));

    if (arr == NULL)
    {
        printf("Memory allocation failed. Exiting program.\n");
        return NULL;
    }

    int count = 0;

    for (int i = 1; i <= x; i++)
    {
        if (x % i == 0)
        {
            arr[count] = i;
            count++;
        }
    }
    return arr;
}

void clearKeyboardBuffer() {
    while (getchar() != '\n');  // Read until the newline character
}

int main()
{
    int m, n;

    printf("Enter two positive integer numbers (comma- separated) : ");

    while (scanf("%d,%d", &m, &n) != 2 || m <= 0 || n <= 0) {
        printf("Invalid input. Retry: ");
        clearKeyboardBuffer();  // clear invalid input
    }

    int* array = newArrayOfDivisors(m);
    printf("Divisor of %d: ", m);
    if (array != NULL) {
        for (int i = 0; i < getNumberOfDivisors(m); i++) {
            printf("%d ", array[i]);
        }
        free(array); // Free allocated memory
    }

    printf("\nGreatest common devisor: gcd(%d, %d) = %d\n", m, n, greatestCommonDivisor(m, n));

    return 0;
}
*/

/*

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

void printArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
    }
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void invertArray(int* array, int size) {
 
    for (int i = 0; i < size; i++) {
        if (i < (size - 1-i))
        {
            swap(&array[i], &array[size - 1 - i]);
        }
    }
}



int* cloneArray(int *array, int size) {
    int* newArray = (int*)malloc(size * sizeof(int));
    if (newArray == NULL) {
        printf("memory allocation failed.........bitte");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < size; i++) {
        newArray[i] = array[i];
    }
    return newArray;
}

int main() {
    int array[9] = { 0 };
    for (int i = 0; i < 9; i++) {
        array[i] = i+1;
    }
    printf("Input %10c : ", ' ');
    printArray(array, 9);
    int *array2 = cloneArray(array, 9);
    if (array2 == NULL) {
        printf("memory allocation failed.........bitte");
        return 0;
    }
  
    printf("\nClone %10c : ", ' ');
    printArray(array2, 9);
    printf("\nInverted %7c : ", ' ');

    invertArray(&array, 9);
    printArray(array, 9);



    free(array2);
    return 0;
}
*/
// 24.2 series expansion page 72

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#define _USE_MATH_DEFINES
#include<math.h>

double sine();
double principalValue();

int main() {
    return 0;
}


