#define _USE_MATH_DEFINES
#include <stdio.h>
#include<math.h>

void locations(double coordinates[][2], int rows);
double largestDistance(double a[7][2], int* locationA, int* locationB);

int main(void)
{
	char* names[] = { "HAW Hamburg", "Eiffel Tower" , "Palma de Mallorca", "Las Vegas", "Copacabana" , "Waikiki Beach", "Surfer's Paradise" };
	double coordinates[7][2] =
	{
		{ 53.557078 ,   10.023109},
		{ 48.858363 ,    2.294481},
		{ 39.562553 ,    2.661947},
		{ 36.156214 , -115.148736},
		{-22.971177 ,  -43.182543},
		{ 21.281004 , -157.837456},
		{-28.002695 ,  153.431781}
	};
	locations(coordinates, 7);
	int locationA;
	int locationB;

	double maxDistance = largestDistance(coordinates, &locationA, &locationB);
	printf(" %d", locationA);
	printf("\nLocation with the largest distance: %s and %s\n ", names[locationA], names[locationB]);
	printf("The maximum distance: %.1f KM", maxDistance);
}

double DistanceKm(double y1, double x1, double y2, double x2)
{

	y1 = (y1 * M_PI) / 180.0;
	y2 = (y2 * M_PI) / 180.0;
	x1 = (x1 * M_PI) / 180.0;
	x2 = (x2 * M_PI) / 180.0;

	double a;

	a = ((sin(y1) * sin(y2)) + ((cos(y1) * cos(y2)) * cos(x2 - x1)));
	return 6378.388 * acos(a);
}

void locations(double coordinates[][2], int rows)
{
	printf("Location coordinates:\n");
	for (int i = 0; i < rows; i++)
	{
		printf("Location %d: (%lf, %lf)\n", i + 1, coordinates[i][0], coordinates[i][1]);
	}
}

double largestDistance(double a[7][2], int* locationA, int* locationB)
{
	double maxDistance = 0.0;
	double distance = 0.0;

	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			distance = DistanceKm(a[i][0], a[i][1], a[j][0], a[j][1]);

			if (distance > maxDistance)
			{
				maxDistance = distance;
				*locationA = i;
				*locationB = j;
			}
		}
	}
	return  maxDistance;
}
