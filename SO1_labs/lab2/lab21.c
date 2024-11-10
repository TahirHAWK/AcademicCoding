#include <stdio.h>

int main() {
    // Labels for columns (a to h)
    char columns[] = "abcdefgh";

    // Print top border
    printf("+- - - -+- - - -+- - - -+- - - -+- - - -+\n");

    // Loop for each row (from 8 to 1)
    for (int row = 8; row >= 1; row--) {
        // Print each cell in the row
        printf("|");
        for (int col = 0; col < 8; col++) {
            printf(" %c%d |", columns[col], row);
        }
        printf("\n");

        // Print border line after each row
        printf("+- - - -+- - - -+- - - -+- - - -+- - - -+\n");
    }

    return 0;
}
