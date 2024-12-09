#include <stdio.h>
#include <stdbool.h>


bool isNorthernHemisphere(double y, double x) {

	if (y >= 0) {
		return true;
	}
	else
		return false;
}

bool isSouthernHemisphere(double y, double x) {

	if (y < 0) {
		return true;
	}
	else
		return false;
}

int main() {

	double y;
	double x;

	printf("Enter the latitude of the location: ");
	scanf_s("%lf", &y);

	printf("Enter the longitude of the location: ");
	scanf_s("%lf", &x);

	if (isNorthernHemisphere(y, x)) {
		printf("\nThe location is in Northern hemisphere");
	}
	else {
		printf("\nThe location is not in Northern hemisphere");
	}

	if (isSouthernHemisphere(y, x)) {
		printf("\nThe location is in Southern hemisphere");
	}
	else {
		printf("\nThe location is not in Southern hemisphere");
	}

}