#include<stdio.h>

#define MAX 20

// Function to print the augmented matrix
void printMatrix(float A[MAX][MAX], int n) {
    printf("\nCurrent Matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n + 1; j++) {
            printf("%10.4f ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int i, j, k, n;
    float A[MAX][MAX], c, x[MAX], sum = 0.0;

    // Input the size of the matrix
    printf("\nEnter the order of matrix: ");
    scanf("%d", &n);

    // Input the augmented matrix row by row
    printf("\nEnter the elements of augmented matrix row-wise:\n\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n + 1; j++) {
            printf("A[%d][%d] : ", i, j);
            scanf("%f", &A[i][j]);
        }
    }

    // Print the initial matrix
    printMatrix(A, n);

    // Forward Elimination: Convert matrix to upper triangular form
    for (j = 1; j <= n; j++) {
        for (i = 1; i <= n; i++) {
            if (i > j) {
                c = A[i][j] / A[j][j]; // Calculate the factor
                for (k = 1; k <= n + 1; k++) {
                    A[i][k] = A[i][k] - c * A[j][k]; // Eliminate elements below the diagonal
                }
            }
        }
        // Print the matrix after each elimination step
        printf("\nMatrix after forward elimination step %d:\n", j);
        printMatrix(A, n);
    }

    // Back Substitution: Calculate the solution
    x[n] = A[n][n + 1] / A[n][n]; // Start with the last variable
    for (i = n - 1; i >= 1; i--) {
        sum = 0;
        for (j = i + 1; j <= n; j++) {
            sum += A[i][j] * x[j]; // Calculate the sum for known variables
        }
        x[i] = (A[i][n + 1] - sum) / A[i][i]; // Solve for the current variable
    }

    // Print the final matrix before displaying the solution
    printf("\nFinal Matrix after Back Substitution:\n");
    printMatrix(A, n);

    // Output the solution
    printf("\nThe solution is: \n");
    for (i = 1; i <= n; i++) {
        printf("\nx%d = %f\t", i, x[i]); // Print the solution values
    }

    return 0;
}
