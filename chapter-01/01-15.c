/* 
 * Rewrite the temperature conversion program of
 * Section 1.2 to use a function for conversion.
 */ 
#include <stdio.h>

#define LOWER 0   /* lower limit of temperature table */
#define UPPER 300 /* upper limit of temperature table */
#define STEP 20   /* step size */

    int fahrenheitToCelsius();

int main()
{
    printf("  F\t C\n");
    fahrenheitToCelsius();
}

int fahrenheitToCelsius()
{
    int fahr;
    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
    {
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    }
    return 0;
}