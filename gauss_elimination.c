#include <stdio.h>
#include <math.h>
#define MAX 10

void printMatrix(float a[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            printf("%0.2f\t", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void gaussElimination(float a[MAX][MAX], int n) {
    // Forward elimination
    for (int i = 0; i < n; i++) {
        // Pivoting
        float maxEl = fabs(a[i][i]);
        int maxRow = i;
        for (int k = i + 1; k < n; k++) {
            if (fabs(a[k][i]) > maxEl) {
                maxEl = fabs(a[k][i]);
                maxRow = k;
            }
        }

        // Swap maximum row with current row
        if (maxRow != i) {
            for (int k = i; k <= n; k++) {
                float temp = a[maxRow][k];
                a[maxRow][k] = a[i][k];
                a[i][k] = temp;
            }
        }

        // Eliminate column entries below the pivot
        for (int k = i + 1; k < n; k++) {
            float factor = a[k][i] / a[i][i];
            for (int j = i; j <= n; j++) {
                a[k][j] -= factor * a[i][j];
            }
        }

        // Print the matrix after each elimination step
        printf("Matrix after elimination for row %d:\n", i);
        printMatrix(a, n);
    }
}

void backSubstitution(float a[MAX][MAX], int n) {
    float x[MAX];
    for (int i = n - 1; i >= 0; i--) {
        x[i] = a[i][n];  // Start with the constant term
        for (int j = i + 1; j < n; j++) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];  // Normalize
    }

    printf("Solution:\n");
    for (int i = 0; i < n; i++) {
        printf("x%d = %0.2f\n", i + 1, x[i]);
    }
}

int main() {
    printf("  Raj Vikram Singh \n SECTION - C \n ROLL NO - 49\n\n");
    int n = 3;  // Number of equations
    float a[MAX][MAX];

    // Enter the augmented matrix (coefficients and constants)
    printf("Enter the augmented matrix (coefficients and constants):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            printf("Enter a[%d][%d]: ", i, j);
            scanf("%f", &a[i][j]);
        }
    }

    gaussElimination(a, n);
    backSubstitution(a, n);

    return 0;
}
