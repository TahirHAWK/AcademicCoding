#include <stdio.h>

int main() {
    // Loop through rows (8 to 1)

    for (int row = 8; row >= 1; --row) 
    {
        // Loop through columns ('a' to 'h')

        for (char col = 'a'; col <= 'h'; ++col)
        {
            // Print the current chessboard field
            printf("%c%d ", col, row);
        } 
        // Move to the next line after completing a row
        printf("\n+- - -+- - -+- - -+- - -+- - -+- - -+- \n");
        printf("\n");
    }

    return 0;
}
