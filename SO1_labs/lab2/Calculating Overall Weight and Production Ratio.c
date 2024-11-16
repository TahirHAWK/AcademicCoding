#include <stdio.h>

int main() {
    unsigned long long total_grains = 0;
    unsigned long long grains_on_field = 1;

    // Sum all grains on the chessboard (fields 1 to 64)
    for (int field = 1; field <= 64; field++) {
        total_grains += grains_on_field;
        grains_on_field *= 2; // Double the grains for the next field
    }

    // Calculate total weight of grains in mg and in tons (1 ton = 1e6 mg)
    double weight_per_grain = 55.0; // mg per grain
    double total_weight_mg = total_grains * weight_per_grain;
    double total_weight_tons = total_weight_mg / 1e6;

    // World wheat production in 2015 in tons
    double world_production_2015 = 735.8e6;

    // Ratio of chessboard wheat weight to world production
    double p = total_weight_tons / world_production_2015;

    // calculate difference for percent increase 
    unsigned long long difference = total_weight_tons - world_production_2015;
    // now the percentage
    unsigned long long percentage = (difference/world_production_2015)*100;

    // Output results
    printf("Total grains on chessboard: %.2e\n", (double)total_grains);
    printf("Total weight of grains: %.2e mg (%.2e tons)\n", total_weight_mg, total_weight_tons);
    printf("Ratio to 2015 world wheat production: %.2e\n", p);

    printf("So the Total weight of grains in the chessboard is %e tons, and it is more than %llu %% more than the world production.\n", total_weight_tons, percentage);
    return 0;
}
