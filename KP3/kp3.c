#include <stdio.h>
#include <float.h>
#include <math.h>
#include <assert.h>

long double f(long double x) {
    return x / (9 + x * x);
}

void create_table() {
    printf("                   Taylor series values table for f(x) = x / (9 + x^2)\n");
    printf(" ------------------------------------------------------------------------------------------\n");
    printf("| x \t| Taylor series\t\t     | Function\t\t          | Iters | Difference\t\t      |\n");
    printf(" -------+------------------------+------------------------+-------+------------------------\n");
}

void print_row(long double x, long double sum, int iter) {
    if (sum < 0) {
        printf("| %.2Lf\t| %.19Lf | %.19Lf | %d\t  | %.19Lf |\n", x, sum, f(x), iter, fabsl(f(x) - sum));
    } else {
        printf("| %.2Lf\t| %.19Lf  | %.19Lf  | %d\t  | %.19Lf |\n", x, sum, f(x), iter, fabsl(f(x) - sum));
    }
}


int main() {
    const long double a = -1,
                      b = 1;
    long double sum, t, k;
    int count = 0;
    int iter;

    printf("Enter number of iterations (n): \n");
    scanf("%d", &iter);
    assert((iter > 0) && "Enter positive number!");
    printf("Enter the coefficient (k): ");
    scanf("%Lf", &k);
    printf("\n\n");
    create_table();

    long double step = (b - a) / iter;
    for (long double x = a; x <= b; x += step) {
        for (int n = 0; n < 99; ++n) {
            t = powl(-1, n) * powl(x, 2 * n + 1) / powl(9, n + 1);
            sum += t;
            ++count;
            if (fabsl(sum - f(x)) < LDBL_EPSILON * k) {
                break;
            }
        }
        print_row(x, sum, count);
        sum = 0;
        count = 0;
    }

    printf(" -----------------------------------------------------------------------------------------\n");
    printf("* machine epsilon (long double) = %.10Le\n", LDBL_EPSILON);
}
