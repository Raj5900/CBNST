/*
Secant Method for Root Finding

The Secant Method is a numerical technique used to find the roots of a function, i.e., the values of xfor which f(x)=0. It is an iterative method that requires two initial guesses and converges to the root by successively improving these guesses.
Formula Explanation

The Secant Method uses the following formula to approximate the root of the function:

x2=x1−f(x1)⋅(x1−x0)f(x1)−f(x0)x2​=x1​−f(x1​)−f(x0​)f(x1​)

Where:

    x0 and x1 are the initial guesses for the root.
    f(x) is the function for which we want to find the root.
    x2 is the new approximation for the root, computed using the current guesses.

Steps of the Secant Method

    Initialization: Start with two initial guesses, x0x0​ and x1x1​.

    Iteration:
        Compute the new approximation x2using the Secant formula.
        Evaluate the function f(x2)at this new approximation.
        Check if f(x2) is within a specified tolerance ee. If so, x2 is considered the root.
        Update x0 and x1 for the next iteration: set x0=x1  x0​=x1​ and x1=x2   x1​=x2​.

    Convergence Check:
        Continue the iterations until either the function value at x2 is less than the tolerance e, or the maximum number of iterations N is reached.

Example

Consider the function f(x)=x^3−5x+1 To find a root:

    Choose initial guesses x0and x1.
    Compute x2using the formula.
    Check if ∣f(x2)∣<e∣. If true, x2​ is the approximate root.
    Update guesses and repeat until convergence or maximum iterations.

Notes

    The Secant Method does not require the derivative of the function, unlike some other methods (e.g., Newton-Raphson).
    It may not always converge, and the choice of initial guesses can affect the result.

For implementation details and to see how this method is applied in practice, refer to the source code provided.


*/




#include <stdio.h>
#include <math.h>

float func(float x) {
    return (x*x*x - 5*x + 1);
}

int main() {
    float x0, x1, e, x2;
    int N;

    
    printf("ENTER ASSUMPTIONS x0 and x1\n");
    scanf("%f %f", &x0, &x1);
    printf("Enter THE TOLERANCE e\n");
    scanf("%f", &e);
    printf("Enter THE MAXIMUM NUMBER OF ITERATIONS N\n");
    scanf("%d", &N);

    
    if (func(x0) == func(x1)) {
        printf("MATHEMATICAL ERROR: func(x0) == func(x1)\n");
        return 0;
    }

    printf("Iteration\t x0\t\t x1\t\t x2\t\t f(x2)\n");

    for (int i = 0; i < N; i++) {
        
        x2 = (x0 * func(x1) - x1 * func(x0)) / (func(x1) - func(x0));

        
        printf("%d\t\t %.6f\t %.6f\t %.6f\t %.6f\n", i + 1, x0, x1, x2, func(x2));

        
        if (fabs(func(x2)) < e) {
            printf("Converged to root: %f\n", x2);
            printf("Number of iterations: %d\n", i + 1);
            return 0;
        }

        
        x0 = x1;
        x1 = x2;
    }

    
    printf("Not convergent within %d iterations\n", N);
    return 0;
}
