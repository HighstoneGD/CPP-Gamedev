#include <math.h>
#include "declarations.h"

int equal_epsilon(double a, double b, double epsilon) {
    if (abs(a - b) < epsilon)
        return 0;
    return 1;
}

enum ErrorType solve_linear(double a, double b, double *x) {
    if (a == 0)
        return ZERO_DIVISION;
    if (a != a || b != b)
        return ARG_IS_NAN;
    if (x == NULL)
        return NULL_POINTER;

    *x = -b/a;
    return SUCCESS;
}

enum ErrorType solve_square(double a, double b, double c, double *x1, double *x2) {
    if (a == 0)
        return ZERO_DIVISION;
    if (a != a || b != b || c != c)
        return ARG_IS_NAN;
    if (x1 == NULL || x2 == NULL)
        return NULL_POINTER;

    double d = b * b - 4 * a * c;

    if (equal_epsilon(d, 0, 0.00000001) == 1)
        if (d < 0)
            return NO_ROOTS;
        else {
            *x1 = (-b - sqrt(d)) / 2 / a;
            *x2 = (-b + sqrt(d)) / 2 / a;
            return SUCCESS;
        }
    
    *x1 = -b / 2 / a;
    *x2 = *x1;
    return SUCCESS;
}