#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct geoCoord
{
    double lats;
    double lons;
};

double degreesToRadians(double degrees);
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


    latitude = (double*)malloc(n, sizeof(double));
    longitude = (double*)malloc(n, sizeof(double));

    printf("\n");

    //read waypoints

    for (int i = 0; i < n; i++)
    {
        printf("Enter waypoints as <latitude> <longitude>: ");

        while (scanf("%lf %lf", &latitude[i], &longitude[i]) != 2)
        {
            clearBuffer();
            printf("Try again (expected <latitude> <longitude>):.\n");
            printf("Enter waypoints as <latitude> <longitude>: ");
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
double distanceKm(double lat1, double lon1, double lat2, double lon2) {
    lat1 = degreesToRadians(lat1);
    lon1 = degreesToRadians(lon1);
    lat2 = degreesToRadians(lat2);
    lon2 = degreesToRadians(lon2);

    double distance = 6371.0 * acos((sin(lat1) * sin(lat2)) + (cos(lat1) * cos(lat2) * cos(lon2 - lon1)));
    return distance;
}

// from degree to radians
double degreesToRadians(double degrees)
{
    return degrees * M_PI / 180.0;
}

// clear the Buffer
void clearBuffer()
{
    while (getchar() != '\n');
}