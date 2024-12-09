#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#define MAX_WAYPOINTS 100
#include <stdio.h>
#include <math.h>

double DistanceKm(double y1, double x1, double y2, double x2);
double getRouteLengthKm(const double latitudes[], const double longitudes[], int n);


int main() {
    FILE* file = fopen("GeoRoute.txt", "r");
    if (!file) {
        printf("Error: Could not open file GeoRoute.txt\n");
        return 1;
    }

    double latitudes[MAX_WAYPOINTS];
    double longitudes[MAX_WAYPOINTS];
    int count = 0;

    // Read latitudes and longitudes from the file
    while (fscanf(file, "%lf,%lf", &latitudes[count], &longitudes[count]) == 2) {
        count++;
        if (count >= MAX_WAYPOINTS) {
            printf("Error: Too many waypoints in the file.\n");
            fclose(file);
            return 1;
        }
    }

    fclose(file);

    // Calculate the total route length
    double routeLength = getRouteLengthKm(latitudes, longitudes, count);

    printf("The total route length is %.2f km.\n", routeLength);

    return 0;
}

// Function to calculate great-circle distance in km
double DistanceKm(double y1, double x1, double y2, double x2) {
    y1 = (y1 * M_PI) / 180;
    y2 = (y2 * M_PI) / 180;
    x1 = (x1 * M_PI) / 180;
    x2 = (x2 * M_PI) / 180;

    double a, d;

    a = ((sin(y1) * sin(y2)) + ((cos(y1) * cos(y2)) * cos(x2 - x1)));
    d = 6378.388 * acos(a);

    return d;
}

// Function to calculate the total route length
double getRouteLengthKm(const double latitudes[], const double longitudes[], int n) {
    double totalDistance = 0.0;

    for (int i = 0; i < n - 1; i++) {
        totalDistance += DistanceKm(latitudes[i], longitudes[i], latitudes[i + 1], longitudes[i + 1]);
    }

    return totalDistance;
}