#include <stdio.h>

int fact(int n) {
    int factorial = 1;
    for (int i = 2; i <= n; i++)
        factorial *= i;
    return factorial;
}

int main() {
    printf("RAJ VIKRAM SINGH \n SECTION - C \n");

    // Sample data
    float x[] = {1891, 1901, 1911, 1921, 1931}; 
    float y[] = {46, 66, 81, 93, 101}; 
    int n = sizeof(x) / sizeof(x[0]);  // Number of data points

    float backward_diff[20][20], value, u, h, result;

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

    // Value to interpolate
    value = 1920;  // Change this to the year you want to interpolate

    h = x[1] - x[0]; 
    u = (value - x[n-1]) / h;  // Note the change for backward interpolation

    result = backward_diff[n-1][0];  // Start with the last y value
    for (int i = 1; i < n; i++) {
        float u_term = u;
        for (int j = 1; j < i; j++) {
            u_term *= (u + j);  // Adjusting for backward interpolation
        }
        result += (u_term * backward_diff[n-1][i]) / fact(i);
    }

    printf("\nThe interpolated population in the year %0.2f is %0.2f\n", value, result);

    return 0;
}
