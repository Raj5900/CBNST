#include <stdio.h>

#define MAX 10

void gaussJordan(float a[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        // Make the diagonal contain all 1s
        float diag = a[i][i];
        for (int j = 0; j <= n; j++) {
            a[i][j] /= diag;
        }

        // Make the other rows contain 0s in the current column
        for (int j = 0; j < n; j++) {
            if (j != i) {
                float factor = a[j][i];
                for (int k = 0; k <= n; k++) {
                    a[j][k] -= factor * a[i][k];
                }
            }
        }
    }
}

void printSolution(float a[MAX][MAX], int n) {
    printf("Solution:\n");
    for (int i = 0; i < n; i++) {
        printf("x%d = %f\n", i + 1, a[i][n]);
    }
}

int main() {
    int n;
    float a[MAX][MAX];

    printf("Enter the number of equations: ");
    scanf("%d", &n);

    printf("Enter the augmented matrix (coefficients and constants):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            scanf("%f", &a[i][j]);
        }
    }

    gaussJordan(a, n);
    printSolution(a, n);

    return 0;
}
