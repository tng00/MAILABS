#include <stdio.h>
#include <float.h>
#include <math.h>

long double f16(long double x) {
    return (3.8 - 3 * sinl(sqrtl(x))) / 0.35;           // 3sin(sqrt(x)) + 0.35x - 3.8 = 0
}

long double f16_der(long double x) {
    return (-30 * cosl(sqrtl(x))) / (7 * sqrtl(x));
}

int IsIterationConvergent(
        long double (*der)(long double),
        long double a,
        long double b) {
    int res = 1;
    long double step = (b - a) / 100;
    for (long double x = a; x <= b; x += step) {
        if (der(x) >= 1) {
            res = 0;
        }
    }
    return res;
}

long double IterationsMethod(
        long double (*f)(long double),
        long double a,
        long double b) {
    long double x0 = (a + b) / 2;
    long double x1 = f(x0);
    while (fabsl(x1 - x0) >= LDBL_EPSILON) {
        x0 = x1;
        x1 = f(x0);
    }
    return x1;
}


long double f28(long double x) {
    return 0.25 * x * x * x + x - 1.2502;                    // 0.25x^3 + x - 1.2502 = 0
}

long double f28_der1(long double x) {
    return 0.75 * x * x + 1;
}

long double f28_der2(long double x) {
    return 1.5 * x;
}

int IsNewtonConvergent(
        long double (*f)(long double),
        long double (*der1)(long double),
        long double (*der2)(long double),
        long double a,
        long double b) {
    int res = 1;
    long double step = (b - a) / 100;
    for (long double x = a; x <= b; x += step) {
        if (fabsl(f(x) * der2(x)) >= powl(der1(x), 2)) {
            res = 0;
        }
    }
    return res;
}

long double NewtonMethod(
        long double (*f)(long double),
        long double (*der)(long double),
        long double a,
        long double b) {
    long double x0 = (a + b) / 2;
    long double x1 = x0 - f(x0) / der(x0);
    while (fabsl(x1 - x0) >= LDBL_EPSILON) {
        x0 = x1;
        x1 = x0 - f(x0) / der(x0);
    }
    return x1;
}



int main() {
    long double a = 2, b = 3;
    printf("Function 16 (Iterations Method):\n\t\t3sin(sqrt(x)) + 0.35x - 3.8 = 0\n");
    if (IsIterationConvergent(f16_der, a, b)) {
        printf("Convergence check:\tOK!\n");

        long double root = IterationsMethod(f16, a, b);
        printf("Approximated root:\t%.10Lf\n", root);

        long double result = 3 * sinl(sqrtl(root)) + 0.35 * root - 3.8;
        printf("Result of inserting root:\t%.10Lf\n\n", result);
    } else {
        printf("Convergence check:\t FAIL!\n\n");
    }


    a = 0;
    b = 2;
    printf("Function 17 (Newton Method):\n\t\t0.25x^3 + x - 1.2502 = 0\n");
    if (IsNewtonConvergent(f28, f28_der1, f28_der2, a, b)) {
        printf("Convergence check:\tOK!\n");

        long double root = NewtonMethod(f28, f28_der1, a, b);
        printf("Approximated root:\t%.10Lf\n", root);

        long double result = f28(root);
        printf("Result of inserting root:\t%.10Lf\n", result);
    } else {
        printf("Convergence check:\t FAIL!\n\n");
    }
}
