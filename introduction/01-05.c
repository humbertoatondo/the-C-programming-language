#include <stdio.h>

#define LOWER  0      /* lower limit of temperature table */
#define UPPER  300    /* upper limit of temperature table */
#define STEP   20     /* step size */

/* Print Fahrenheit-Celsius table */
int main()
{
    printf("  F\t C\n");
    int fahr;
    for (fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP) {
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
    }
}
