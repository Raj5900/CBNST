#include <stdio.h>


int fact(int n) {
    int factorial = 1;
    for (int i = 2; i <= n; i++)
        factorial *= i;
    return factorial;
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
    printf("Enter the (x values):\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d]: ", i);
        scanf("%f", &x[i]);
    }

    printf("Enter the corresponding values (y values):\n");
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
    printf("Enter the value  for interpolation: ");
    scanf("%f", &value);

    float forward_diff[20][20];

    // Initialize forward difference table
    for (int i = 0; i < n; i++) {
        forward_diff[i][0] = y[i];
    }

    // Calculate forward differences
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            forward_diff[i][j] = forward_diff[i + 1][j - 1] - forward_diff[i][j - 1];
        }
    }

    // Display forward difference table
    printf("\nForward Difference Table:\n");
    for (int i = 0; i < n; i++) {
        printf("%0.2f", x[i]);
        for (int j = 0; j < n - i; j++) {
            printf("\t%0.2f", forward_diff[i][j]);
        }
        printf("\n");
    }

    // Calculate u
    float u = (value - x[0]) / h;

    // Calculate interpolated result
    float result = y[0];
    for (int i = 1; i < n; i++) {
        float u_term = u;
        for (int j = 1; j < i; j++) {
            u_term *= (u - j);
        }
        result += (u_term * forward_diff[0][i]) / fact(i);
    }

    printf("\nThe interpolated value  %0.2f is %0.2f\n", value, result);
    
    return 0;
}
