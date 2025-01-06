#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double distanceKm(double lat1, double lon1, double lat2, double lon2);
void clearBuffer();

int main(void)
{
    double totalDistance = 0.0;
    double* latitude;
    double* longitude;
    int n = 0;

    printf("Enter number of waypoints: ");
    while (scanf("%d", &n) != 1)
    {
        clearBuffer();
        printf("Try again (a number that is >= 0 is expected ).\n");
    }

    latitude = (double*)malloc(n * sizeof(double));
    longitude = (double*)malloc(n * sizeof(double));

    printf("\n");

    //read waypoints

    for (int i = 0; i < n; i++)
    {
        printf("Enter waypoints %d as <latitude> <longitude>: ", i + 1);

        while (scanf("%lf %lf", &latitude[i], &longitude[i]) != 2)
        {
            clearBuffer();
            printf("Try again (expected <latitude> <longitude>):.\n");
            printf("Enter waypoints %d as <latitude> <longitude>: ", i + 1);
        }
    }

    // calculate the total distance
    for (int i = 1; i < n; i++)
    {
        double lat1 = latitude[i - 1];
        double lon1 = longitude[i - 1];
        double lat2 = latitude[i];
        double lon2 = longitude[i];

        totalDistance += distanceKm(lat1, lon1, lat2, lon2);
    }
    printf("By taking this route you will travel %.3f km\n", totalDistance);

    free(latitude);
    free(longitude);

    return 0;
}

// calculate the distance between 2 points
double distanceKm(double y1, double x1, double y2, double x2) {
    y1 = (y1 * M_PI) / 180;
    y2 = (y2 * M_PI) / 180;
    x1 = (x1 * M_PI) / 180;
    x2 = (x2 * M_PI) / 180;

    double a, d;

    a = ((sin(y1) * sin(y2)) + ((cos(y1) * cos(y2)) * cos(x2 - x1)));
    d = 6378.388 * acos(a);

    return d;
}

// clear the Buffer
void clearBuffer()
{
    while (getchar() != '\n');
}