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
    float x[] = {1891, 1901, 1911, 1921, 1931}; 
    float y[] = {46, 66, 81, 93, 101}; 
    int n = sizeof(x) / sizeof(x[0]);  // Number of data points

    float forward_diff[20][20], value, u, h, result;

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

    // Interpolation value
    value = 1895;

    // Calculate h and u
    h = x[1] - x[0]; 
    u = (value - x[0]) / h;

    // Calculate interpolated result
    result = y[0];
    for (int i = 1; i < n; i++) {
        float u_term = u;
        for (int j = 1; j < i; j++) {
            u_term *= (u - j);
        }
        result += (u_term * forward_diff[0][i]) / fact(i);
    }

    printf("\nThe interpolated population in the year %0.2f is %0.2f\n", value, result);
    
    return 0;
}
