#include <stdio.h>

#define MAX 20

// Function to print the current state of the matrix
void printMatrix(float A[MAX][MAX], int n) {
    printf("\nCurrent matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n + 1; j++) {
            printf("%8.2f ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int i, j, k, n;
    float A[MAX][MAX], c, x[MAX];
    
    // Input matrix size
    printf("\nEnter the size of the matrix (number of variables): ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX) {
        printf("Invalid matrix size. Please enter a positive integer <= %d.\n", MAX);
        return 1;
    }

    // Input the augmented matrix row-wise
    printf("\nEnter the elements of the augmented matrix row-wise:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n + 1; j++) {
            printf(" A[%d][%d]: ", i, j);
            if (scanf("%f", &A[i][j]) != 1) {
                printf("Invalid input. Please enter numeric values.\n");
                return 1;
            }
        }
    }

    // Gauss-Jordan Elimination process
    for (j = 1; j <= n; j++) {
        if (A[j][j] == 0) {
            printf("Mathematical error! Division by zero detected.\n");
            return 1;
        }
        for (i = 1; i <= n; i++) {
            if (i != j) {
                c = A[i][j] / A[j][j];
                for (k = 1; k <= n + 1; k++) {
                    A[i][k] -= c * A[j][k];
                }
            }
        }
        // Normalize the pivot row
        for (k = 1; k <= n + 1; k++) {
            A[j][k] /= A[j][j];
        }
        
        // Print the matrix after each elimination step
        printf("\nMatrix after making column %d a unit column:\n", j);
        printMatrix(A, n);
    }

    // The solutions are now in the last column of the matrix
    printf("\nThe solution is:\n");
    for (i = 1; i <= n; i++) {
        x[i] = A[i][n + 1];
        printf("\n x%d = %f", i, x[i]);
    }

    return 0;
}
