#include <stdio.h>
#include<math.h>
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

void gaussJordan(float a[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        // Find the maximum element in the current column
        float maxEl = fabs(a[i][i]);
        int maxRow = i;
        for (int k = i + 1; k < n; k++) {
            if (fabs(a[k][i]) > maxEl) {
                maxEl = fabs(a[k][i]);
                maxRow = k;
            }
        }

        // Swap maximum row with current row (if needed)
        if (maxRow != i) {
            for (int k = i; k <= n; k++) {
                float temp = a[maxRow][k];
                a[maxRow][k] = a[i][k];
                a[i][k] = temp;
            }
        }

        // Normalize the pivot row
        float diag = a[i][i];
        for (int j = 0; j <= n; j++) {
            a[i][j] /= diag;  // Make the pivot 1
        }

        // Print matrix after making the pivot 1
        printf("Matrix after making a[%d][%d] = 1:\n", i, i);
        printMatrix(a, n);

        // Make the other rows contain 0s in the current column
        for (int j = 0; j < n; j++) {
            if (j != i) {
                float factor = a[j][i];
                for (int k = 0; k <= n; k++) {
                    a[j][k] -= factor * a[i][k];  // Eliminate
                }
            }
        }

        // Print matrix after eliminating column
        printf("Matrix after eliminating column %d:\n", i);
        printMatrix(a, n);
    }
}

void printSolution(float a[MAX][MAX], int n) {
    printf("Solution:\n");
    for (int i = 0; i < n; i++) {
        printf("x%d = %0.2f\n", i + 1, a[i][n]);
    }
}

int main() {
    printf("  Prakhar Tyagi \n SECTION - C \n ROLL NO - 42\n\n");
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

    gaussJordan(a, n);
    printSolution(a, n);

    return 0;
}
