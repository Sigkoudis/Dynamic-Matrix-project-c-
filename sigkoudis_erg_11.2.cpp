#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void fillPin2D(int **array, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            *(*(array + i) + j) = rand() % 10 + 1;
        }
    }
}

void showPin2D(int **array, int n) {
    printf("p =\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%2d ", *(*(array + i) + j));
        }
        printf("\n");
    }
}
void showPinDouble1D(double *array, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.1f ", *(array + i));
    }
    printf("\n");
}
void findMeanLine(int **array, int n, double *avgLine) {
    for (int i = 0; i < n; i++) {
        double sum = 0;
        for (int j = 0; j < n; j++) {
            sum += *(*(array + i) + j);
        }
        *(avgLine + i) = sum / n;
    }
}
void findMeanCol(int **array, int n, double *avgCol) {
    for (int j = 0; j < n; j++) {
        double sum = 0;
        for (int i = 0; i < n; i++) {
            sum += *(*(array + i) + j);
        }
        *(avgCol + j) = sum / n;
    }
}
int findDSum(int **array, int n) {
    int sum1D = 0, sum2D = 0;
    for (int i = 0; i < n; i++) {
        sum1D += *(*(array + i) + i);
        sum2D += *(*(array + i) + (n - i - 1));
    }
    printf("sum1D = %d\n", sum1D);
    printf("sum1D + sum2D = %d\n", sum1D + sum2D);
    return sum1D + sum2D;
}
main() 
{
    int n;
    do
 {
 printf("Give an integer number n > 5 \n");
 scanf("%d", &n);
 }
 while ( n <= 5);
    int **my2DArray = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        *(my2DArray + i) = (int *)malloc(n * sizeof(int));
    }
    double *avgLine = (double *)malloc(n * sizeof(double));
    double *avgCol = (double *)malloc(n * sizeof(double));
    srand(time(NULL));
    fillPin2D(my2DArray, n);
    showPin2D(my2DArray, n);
    findMeanLine(my2DArray, n, avgLine);
    printf("avgLine = ");
    showPinDouble1D(avgLine, n);
    findMeanCol(my2DArray, n, avgCol);
    printf("avgCol = ");
    showPinDouble1D(avgCol, n);
    int diagonalSum = findDSum(my2DArray, n);
    printf("Diagonal Sum = %d\n", diagonalSum);
system("Pause");
}
