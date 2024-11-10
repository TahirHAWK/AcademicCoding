#include <stdio.h>
#include <limits.h>

int main() {
    printf("Field | On field   | Sum\n");
    printf("------|------------|----------------------------\n");

    // Variables for grains and cumulative sum, using different data types
    unsigned short grains_short = 1;
    unsigned short sum_short = 1;
    unsigned int grains_int = 1;
    unsigned int sum_int = 1;
    unsigned long grains_long = 1;
    unsigned long sum_long = 1;
    unsigned long long grains_long_long = 1;
    unsigned long long sum_long_long = 1;

    // Print the first field manually
    printf("%2d    | %10u | %22llu (= %.1e)\n", 1, grains_long_long, sum_long_long, (double)sum_long_long);

    // Loop through fields 2 to 64
    for (int field = 2; field <= 64; field++) {
        // Double the grains on each field
        grains_short *= 2;
        sum_short += grains_short;

        grains_int *= 2;
        sum_int += grains_int;

        grains_long *= 2;
        sum_long += grains_long;

        grains_long_long *= 2;
        sum_long_long += grains_long_long;

        // Print results for unsigned long long (can change data type as needed)
        printf("%2d    | %10llu | %22llu (= %.1e)\n", field, grains_long_long, sum_long_long, (double)sum_long_long);
    }

    printf("------|------------|----------------------------\n");

    return 0;
}
