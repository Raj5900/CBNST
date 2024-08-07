#include <stdio.h>
#include <math.h>

// Function prototype
float func(float x);

// Function definition
float func(float x) {
    return (x*x*x) - (2*x) - 5;
}

int main() {
    float a, b, e;
    int count = 0;

    // Display header information
    printf("  RAJ VIKRAM SINGH \n SECTION - C \n ROLL NO - 49\n\n");

    // Input values for a, b, and e
    printf("ENTER A, B, e\n");
    scanf("%f%f%f", &a, &b, &e);

    // Check if the initial values are valid
    if (func(a) * func(b) > 0) {
        printf("INVALID VALUES: The function does not change sign in the interval [a, b].\n");
        return 0;
    }

    // Output header for results
    printf("\nO   U   T   P   U   T\n\n");
    printf("        a               b               c\n");

    float c = 0;

    // Iteration loop for False Position method
    while (fabs(a - b) > e) {
        count++;
        c = (a * func(b) - b * func(a)) / (func(b) - func(a));

        // Break if function value at c is sufficiently close to zero
        if (fabs(func(c)) < e) {
            break;
        }
        // Update the interval [a, b]
        if (func(c) * func(a) < 0) {
            b = c;
        } else {
            a = c;
        }

        // Print the current values of a, b, and c
        printf("        %10.6f    %10.6f    %10.6f\n", a, b, c);
    }

    // Print the final result
    printf("FINAL ROOT  :    %10.6f\n", c);
    printf("NUMBER OF ITERATIONS :   %d\n", count);

    return 0;
}
