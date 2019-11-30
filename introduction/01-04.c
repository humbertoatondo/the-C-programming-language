#include <stdio.h>

#define LOWER  0      /* Lower limit of temperature table */
#define UPPER  300    /* Upper limit of temperature table */
#define STEP   20     /* Step size */

/* Print Celsius-Fahrenheit table */
int main()
{
    printf("  C\t F\n");
    int celsius;
    for (celsius = LOWER; celsius <= UPPER; celsius = celsius + STEP) {
        printf("%3d %6.1f\n", celsius, ((celsius * 9.0) / 5.0) + 32);
    }
}
