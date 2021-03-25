#include <stdlib.h>
#include <stdio.h>
#include "initialization.c"

int main() {
    double x;
    if (solve_linear(2, -4, &x) == SUCCESS)
        printf("x = %.2f\n", x);

    double x1, x2;
    if (solve_square(1, 5, 6, &x1, &x2) == SUCCESS)
        printf("x1 = %.2f, x2 = %.2f\n", x1, x2);

    return 0;
}