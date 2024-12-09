#define _USE_MATH_DEFINES
#define NUM_LOCATIONS 7
#include <stdio.h>
#include <math.h>


double DistanceKm(double y1, double x1, double y2, double x2);
double getMaximumDistance(const double coords[][2], int n, int* indexA, int* indexB);



int main() {
    // Names of the locations
    const char* names[NUM_LOCATIONS] = {
        "HAW Hamburg",
        "Eiffel Tower",
        "Palma de Mallorca",
        "Las Vegas",
        "Copacabana",
        "Waikiki Beach",
        "Surfer's Paradise"
    };

    // Coordinates of the locations
    const double coords[NUM_LOCATIONS][2] = {
        {53.557078, 10.023109},
        {48.858363, 2.294481},
        {39.562553, 2.661947},
        {36.156214, -115.148736},
        {-22.971177, -43.182543},
        {21.281004, -157.837456},
        {-28.002695, 153.431781}
    };

    int indexA, indexB;
    double maxDistance = getMaximumDistance(coords, NUM_LOCATIONS, &indexA, &indexB);

    // Output the result
    printf("%s and %s have the largest distance (%.2f km).\n",
        names[indexA], names[indexB], maxDistance);
    printf("You\'d better not walk. Take a flight, instead.\n");

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

// Function to find the maximum distance between any two locations
double getMaximumDistance(const double coords[][2], int n, int* indexA, int* indexB) {
    double maxDistance = 0.0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { // Compare every pair of locations
            double distance = DistanceKm(coords[i][0], coords[i][1], coords[j][0], coords[j][1]);
            if (distance > maxDistance) {
                maxDistance = distance;
                *indexA = i;
                *indexB = j;
            }
        }
    }

    return maxDistance;
}