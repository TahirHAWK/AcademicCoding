#define _USE_MATH_DEFINES
#include<stdio.h>
#include<math.h>




double localDistanceKm(double y1, double x1, double y2, double x2) {

	double y;
	double x;
	double d;
	double a;



	y = 111.3 * (fabs(y1 - y2));
	a = (y1 + y2) / 2;
	a = (a * M_PI) / 180;

	x = 111.3 * cos(a) * (fabs(x1 - x2));

	d = sqrt(pow(x, 2) + pow(y, 2));



}

double DistanceKm(double y1, double x1, double y2, double x2) {

	y1 = (y1 * M_PI) / 180;
	y2 = (y2 * M_PI) / 180;
	x1 = (x1 * M_PI) / 180;
	x2 = (x2 * M_PI) / 180;

	double a;
	double d;

	a = ((sin(y1) * sin(y2)) + ((cos(y1) * cos(y2)) * cos(x2 - x1)));
	d = 6378.388 * acos(a);


}


int main() {



	double y1 = 53.557078;
	double x1 = 10.023109;


	double latitudes[7] = { 53.557078,48.858363,39.562553,36.156214,-22.971177,21.281004,-28.002695 };
	double longitudes[7] = { 10.023109,2.294481,2.661947,-115.148736 ,-43.182543 ,-157.837456 ,153.431781 };
	char* arr[] = { "HAW Hamburg","Eiffel Tower","Palma de Mallorca","Las Vegas","Copacabana","Waikiki Beach","Surfers Paradise" };

	printf("|      Location       |      latitude        |      longitude       |      Distance        |     Local distance   | \n");
	printf("|_____________________|______________________|______________________|______________________|______________________| \n");


	for (int i = 0; i < 7; i++) {

		double a;
		double b;
		a = latitudes[i];
		b = longitudes[i];
		printf("|%20s | %20lf | %20lf | %20.1lf | %20.1lf |\n", arr[i], a, b, DistanceKm(y1, x1, a, b), localDistanceKm(y1, x1, a, b));
	}


	return 0;
}