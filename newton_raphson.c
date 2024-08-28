#include <stdio.h>
#include <math.h>

// Function prototype
float func(float x);
float deriv(float x);

// Function definition for the function whose root is to be found
float func(float x) {
    return cosf(x) - x * expf(x);
}

// Function definition for the derivative of the function
float deriv(float x) {
    return -sinf(x) - expf(x) * (1 + x);
}

int main() {
    float x0, x1, e, fx, dfx;
    int itr;

    // Display header information
    printf("  RAJ VIKRAM SINGH \n SECTION - C \n ROLL NO - 49\n\n");

    // Input values for x0 and tolerance e
    printf("ENTER x0, tolerance e\n");
    scanf("%f %f", &x0, &e);
    
    itr = 0;
    printf("\nO   U   T   P   U   T\n\n");
    printf("Iteration |   x0       |   x1       |   f(x1)\n");

    while (itr < 100) // Increased iteration limit for robustness
    {
        fx = func(x0);
        dfx = deriv(x0); // Use the derivative function
        
        if (dfx == 0) {
            printf("Derivative is zero. Newton's method fails.\n");
            return 0;
        }
        
        x1 = x0 - fx / dfx;

        // Print the current values of x0, x1, and f(x1)
        printf("%4d      | %10.6f | %10.6f | %10.6f\n", itr + 1, x0, x1, func(x1));

        if (fabs(x1 - x0) < e) {
            printf("Solution found: %10.6f\n", x1);
            printf("NUMBER OF ITERATIONS : %d\n", itr + 1);
            return 0;
        }
        
        x0 = x1;
        itr++;
    }

    printf("Solution not found within the maximum number of iterations.\n");
    printf("NUMBER OF ITERATIONS : %d\n", itr);
    return 0;
}
