#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a structure to hold geographic coordinates
struct geoCoord {
    double latitude;
    double longitude;
};

// Function prototypes
double distanceKm(double lat1, double lon1, double lat2, double lon2);
void clearBuffer();

int main(void)
{
    double totalDistance = 0.0;
    struct geoCoord* waypoints; // Pointer to hold dynamically allocated array of waypoints
    int n = 0;

    // Ask user for the number of waypoints
    printf("Enter number of waypoints: ");
    while (scanf("%d", &n) != 1 || n <= 0) {
        clearBuffer();
        printf("Try again (a number that is >= 0 is expected).\n");
    }

    // Dynamically allocate memory for waypoints
    waypoints = (struct geoCoord*)malloc(n * sizeof(struct geoCoord));
    if (waypoints == NULL) {
        printf("Memory allocation failed. Exiting program.\n");
        return 1;
    }

    printf("\n");

    // Read waypoints from the user
    for (int i = 0; i < n; i++) {
        printf("Enter waypoints %d as <latitude> <longitude>: ", i + 1);
        while (scanf("%lf %lf", &waypoints[i].latitude, &waypoints[i].longitude) != 2) {
            clearBuffer();
            printf("Try again (expected <latitude> <longitude>):\n");
            printf("Enter waypoints %d as <latitude> <longitude>: ", i + 1);
        }
    }

    // Calculate the total distance
    for (int i = 1; i < n; i++) {
        double lat1 = waypoints[i - 1].latitude;
        double lon1 = waypoints[i - 1].longitude;
        double lat2 = waypoints[i].latitude;
        double lon2 = waypoints[i].longitude;

        totalDistance += distanceKm(lat1, lon1, lat2, lon2);
    }
    printf("By taking this route you will travel %.3f km\n", totalDistance);

    // Free dynamically allocated memory
    free(waypoints);

    return 0;
}

// Function to calculate the distance between two points
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

// Function to clear the input buffer
void clearBuffer()
{
    while (getchar() != '\n');
}
