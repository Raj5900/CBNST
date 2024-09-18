#include <stdio.h>
#include <math.h>

double f(double x) {
    return cos(x) - x * exp(x);
}

double f_prime(double x) {
    return -sin(x) - exp(x) - x * exp(x);
}
double newton_method(double initial_guess, double tolerance, int max_iterations) {
    double x = initial_guess;
    int iteration = 0;

    printf("Iteration\tValue of x\tf(x)\t\tf'(x)\n");
    printf("------------------------------------------------------------\n");

    while (iteration < max_iterations) {
        double fx = f(x);
        double fx_prime = f_prime(x);

        printf("%d\t\t%lf\t%lf\t%lf\n", iteration, x, fx, fx_prime);

        if (fabs(fx_prime) < 1e-10) { // Avoid division by very s
            printf("Derivative too small; no convergence.\n");
            return x;
        }

        double x_new = x - fx / fx_prime;

        if (fabs(x_new - x) < tolerance) {
            return x_new; // Converged to a solution
        }

        x = x_new;
        iteration++;
    }

    printf("Maximum iterations reached; no convergence.\n");
    return x;
}

int main() {
    double initial_guess;
    double tolerance;
    int max_iterations;
printf("Name : Udit Rohal\nSection : C\nRoll No. 65\n");
    printf("Enter the initial guess: ");
    scanf("%lf", &initial_guess);

    printf("Enter the tolerance: ");
    scanf("%lf", &tolerance);

    printf("Enter the maximum number of iterations: ");
    scanf("%d", &max_iterations);

    double root = newton_method(initial_guess, tolerance, max_iterations);

    printf("Root found: %lf\n", root);
    return 0;
}
