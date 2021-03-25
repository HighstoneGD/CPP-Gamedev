enum ErrorType {
    SUCCESS,
    ZERO_DIVISION,
    ARG_IS_NAN,
    NULL_POINTER,
    NO_ROOTS
};

int equal_epsilon(double a, double b, double epsilon);

enum ErrorType solve_linear(double a, double b, double *x);

enum ErrorType solve_square(double a, double b, double c, double *x1, double *x2);