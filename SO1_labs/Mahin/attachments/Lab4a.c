#define _USE_MATH_DEFINES
#define SIZE 9
#include <stdio.h>
#include<math.h>

double DistanceKm(double y1, double x1, double y2, double x2);
void getTotalDistance(double* lat, double* lon, double* d);

int main(void)
{
	double distance = 0.0;
	double latitude[SIZE] = { 53.557029 , 53.557166 , 53.557274 , 53.560288 , 53.561306 , 53.562015 , 53.558241 , 53.557900 ,53.557203 };
	double longitude[SIZE] = { 10.022918 , 10.021343 , 10.020297 , 10.014906 , 10.015426 , 10.016568 , 10.023244 , 10.022142 , 10.022632 };
	getTotalDistance(latitude, longitude, &distance);
	printf("%lf", distance);

}

double DistanceKm(double y1, double x1, double y2, double x2)
{

	y1 = (y1 * M_PI) / 180.0;
	y2 = (y2 * M_PI) / 180.0;
	x1 = (x1 * M_PI) / 180.0;
	x2 = (x2 * M_PI) / 180.0;

	double a;

	a = ((sin(y1) * sin(y2)) + ((cos(y1) * cos(y2)) * cos(x2 - x1)));
	return 6378.388 * acos(a);;
}

void getTotalDistance(double* lat, double* lon, double* d)
{
	for (int i = 0; i < SIZE - 1; i++)
	{
		*d += DistanceKm(lat[i], lon[i], lat[i + 1], lon[i + 1]);
	}
}