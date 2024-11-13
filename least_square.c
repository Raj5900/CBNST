#include <stdio.h>
#define MAX 100
void gaussJordan(double a[MAX][MAX + 1], int n) {
    int i, j, k;
    double temp;
    for (i = 0; i < n; i++) {
        temp = a[i][i];
        for (j = 0; j <= n; j++) {
            a[i][j] /= temp;
        }
        for (j = 0; j < n; j++) {
            if (i != j) {
                temp = a[j][i];
                for (k = 0; k <= n; k++) {
                    a[j][k] -= temp * a[i][k];
                }
            }
        }
    }
}
void leastSquares(double x[], double y[], int n) {
    double a[MAX][MAX + 1]; 
    double sumX = 0, sumY = 0, sumXX = 0, sumXY = 0;
    for (int i = 0; i < n; i++) {
        sumX += x[i];
        sumY += y[i];
        sumXX += x[i] * x[i];
        sumXY += x[i] * y[i];
    }
    a[0][0] = n;
    a[0][1] = sumX;
    a[0][2] = sumY;
    a[1][0] = sumX;
    a[1][1] = sumXX;
    a[1][2] = sumXY;
    printf("%0.1f = %da + b%0.1f\n",sumY,n,sumX);
    printf("%0.1f = %0.1fa + b%0.1f\n",sumXY,sumX,sumXX);
    gaussJordan(a, 2); // We have two unknowns, m and c (slope and intercept)
    printf("by using the gauss jordan the values of a and b is %lf ,%lf",a[1][2], a[0][2]);
    printf("\nThe Least Squares line is: y = %.2lfx + %.2lf\n", a[1][2], a[0][2]);
}
void main() {
    int n;
    double x[MAX], y[MAX];
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    printf("Enter the x and y values:\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d]: ", i + 1);
        scanf("%lf", &x[i]);
        printf("y[%d]: ", i + 1);
        scanf("%lf", &y[i]);
    }
    leastSquares(x, y, n);
}
