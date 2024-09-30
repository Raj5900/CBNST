#include <stdio.h>
#include <math.h>

// Function f(x) = cos(x) - 3x + 1
double fun(double x) {
    return cos(x) - 3 * x + 1;
}

// Rearranged functions for fixed-point iteration
double g1(double x) {
    return (cos(x) + 1) / 3;
}

double g2(double x) {
    return acos(3 * x - 1);
}

int main() {
    double x0, x, error;
    int itr = 0;
    double a, b;

    // Input initial guesses
    printf("Enter two initial guesses a and b: ");
    scanf("%lf %lf", &a, &b);

    // Check if initial guesses are valid
    if (fun(a) * fun(b) >= 0) {
        printf("Invalid initial guesses. Try again.\n");
        return 1;
    }

    // Choose the closer guess (a or b) as starting point
    x0 = (fabs(fun(a)) < fabs(fun(b))) ? a : b;
    printf("Starting with initial guess x0 = %lf\n", x0);

    // Input error tolerance
    printf("Enter the acceptable error value: ");
    scanf("%lf", &error);

    // Start iteration using g1(x)
    do {
        x = g1(x0); // Apply fixed-point formula
        printf("Iteration %d: x = %lf, f(x) = %lf\n", itr, x, fun(x));
        x0 = x;
        itr++;
    } while (fabs(fun(x)) >= error);

    // Output final result
    printf("Approximate root found: %lf\n", x);
    printf("Total iterations: %d\n", itr);

    return 0;
}
