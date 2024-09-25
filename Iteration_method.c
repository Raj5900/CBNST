#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double fun(double x) {
    double val = 3.14 / 180.00; // Conversion factor from degrees to radians
    return cos(x * val) - 3 * x + 1;
}

double g(double x, int choice) {
    double val = 3.14 / 180.00; // Conversion factor
    if (choice == 1) {
        return (cos(x * val) + 1) / 3; // Rearranged function for fixed-point iteration
    } else {
        return acos((3 * x - 1) * val); // Alternate function for fixed-point iteration
    }
}

double g_prime1(double x) {
    double val = 3.14 / 180.00; // Conversion factor
    return (-sin(x * val)) / 3; // Derivative of first choice function
}

double g_prime2(double x) {
    double val = 3.14 / 180.00; // Conversion factor
    return -3 / sqrt(1 - pow((3 * x - 1) * val, 2)); // Derivative of second choice function
}

int main() {
    double x0, x, error;
    int itr = 0;
    double a, b;

    printf("Name: Raj Vikram Singh\n"); // Your name
    printf("Section: C\n");
    printf("Roll No: 49\n");
    printf("Input the initial guesses a and b: ");
    scanf("%lf %lf", &a, &b);

    if (fun(a) * fun(b) >= 0) {
        printf("INVALID INITIAL GUESS\n");
        return 1;
    }

    double t1 = fabs(fun(a));
    double t2 = fabs(fun(b));
    x0 = (t1 < t2) ? a : b; // Choose the closer initial guess
    printf("Initial guess considered x: %lf\n", x0);

    printf("Input the error value: ");
    scanf("%lf", &error);

    // Determine which function to use based on the derivatives
    double val1 = fabs(g_prime1(x0));
    double val2 = fabs(g_prime2(x0));
    int choice = 0;

    if (val1 < 1 && val2 < 1) {
        choice = (val1 < val2) ? 1 : 0; // Choose the one with a smaller derivative
    } else if (val1 < 1) {
        choice = 1;
    } else {
        choice = 0;
    }

    do {
        x = g(x0, choice); // Perform iteration
        printf("xn = %lf , g(xn) = %lf , xn-1 = %lf where n=%d\n", x, g(x, choice), x0, itr);
        x0 = x;
        itr++;
    } while (fabs(fun(x)) >= error);

    printf("The final approximate root: %lf\n", x);
    printf("Number of iterations: %d\n", itr);
    
    return 0;
}
