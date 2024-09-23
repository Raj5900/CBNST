#include <stdio.h>

int fact(int n) {
    int factorial = 1;
    for (int i = 2; i <= n; i++)
        factorial *= i;
    return factorial;
}

void displayBackwardDiffTable(float x[], float y[], int n) {
    float backward_diff[20][20];

    // Initialize backward difference table
    for (int i = 0; i < n; i++) {
        backward_diff[i][0] = y[i];
    }

    // Calculate backward differences
    for (int j = 1; j < n; j++) {
        for (int i = n - 1; i >= j; i--) {
            backward_diff[i][j] = backward_diff[i][j - 1] - backward_diff[i - 1][j - 1];
        }
    }

    // Display backward difference table
    printf("\nBackward Difference Table:\n");
    for (int i = 0; i < n; i++) {
        printf("%0.2f", x[i]);
        for (int j = 0; j <= i; j++) {
            printf("\t%0.2f", backward_diff[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Student Information
    printf("RAJ VIKRAM SINGH \nSECTION - C \nRoll No: 49\n");

    // Data points
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    if (n < 2) {
        printf("At least two data points are required.\n");
        return 0;
    }

    float x[n], y[n], value;

    // Input for x and y arrays
    printf("Enter the years (x values):\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d]: ", i);
        scanf("%f", &x[i]);
    }

    printf("Enter the corresponding population (y values):\n");
    for (int i = 0; i < n; i++) {
        printf("y[%d]: ", i);
        scanf("%f", &y[i]);
    }

    // Check for uniform spacing
    float h = x[1] - x[0];
    int isUniform = 1;  // Flag for uniformity

    for (int i = 1; i < n - 1; i++) {
        if (x[i + 1] - x[i] != h) {
            isUniform = 0;
            break;
        }
    }

    if (!isUniform) {
        printf("NO UNIFORM POINTS \n");
        return 0;
    }

    // Input for the interpolation value
    printf("Enter the year for interpolation: ");
    scanf("%f", &value);

    // Backward Interpolation
    float u = (value - x[n - 1]) / h;  // Normalize u based on last x value
    float result_backward = y[n - 1];
    
    for (int i = 1; i < n; i++) {
        float u_term = u;
        for (int j = 1; j < i; j++) {
            u_term *= (u + j);
        }
        result_backward += (u_term * (y[n - i] - y[n - i - 1])) / fact(i);
    }

    // Display Backward Difference Table
    displayBackwardDiffTable(x, y, n);

    printf("\nThe interpolated population in the year %0.2f (Backward) is %0.2f\n", value, result_backward);
    
    return 0;
}
