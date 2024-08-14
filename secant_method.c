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
