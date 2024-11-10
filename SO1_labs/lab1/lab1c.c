#include <stdio.h>

int main() {
    int year, sum, thousands, hundreds, tens, units;
    
    // Prompt the user for their birth year
    printf("Please enter your birth year (e.g., 2016): ");
    scanf("%d", &year);

    // Extract each digit
    thousands = year / 1000;         // Get the thousands digit
    hundreds = (year / 100) % 10;    // Get the hundreds digit
    tens = (year / 10) % 10;         // Get the tens digit
    units = year % 10;               // Get the units digit

    // Calculate the digit sum
    sum = thousands + hundreds + tens + units;

    // Print the result
    printf("The digit sum of %d is %d + %d + %d + %d = %d.\n", 
           year, thousands, hundreds, tens, units, sum);

    return 0;
}
