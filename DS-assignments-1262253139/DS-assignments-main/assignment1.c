#include <stdio.h>
#define MAX 10

void readMatrix(int a[MAX][MAX], int *r, int *c)
{
    int i, j;
    printf("Enter rows and columns: ");
    scanf("%d%d", r, c);
    printf("Enter matrix elements:\n");
    for (i = 0; i < *r; i++)
        for (j = 0; j < *c; j++) scanf("%d", &a[i][j]);
}

void displayMatrix(int a[MAX][MAX], int r, int c)
{
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) printf("%d\t", a[i][j]);
        printf("\n");
    }
}

void addMatrix(int a[MAX][MAX], int b[MAX][MAX], int r, int c)
{
    int i, j, result[MAX][MAX];
    for (i = 0; i < r; i++) for (j = 0; j < c; j++) result[i][j] = a[i][j] + b[i][j];
    printf("Addition:\n"); displayMatrix(result, r, c);
}

void subtractMatrix(int a[MAX][MAX], int b[MAX][MAX], int r, int c)
{
    int i, j, result[MAX][MAX];
    for (i = 0; i < r; i++) for (j = 0; j < c; j++) result[i][j] = a[i][j] - b[i][j];
    printf("Subtraction:\n"); displayMatrix(result, r, c);
}

void multiplyMatrix(int a[MAX][MAX], int b[MAX][MAX], int r1, int c1, int c2)
{
    int i, j, k, result[MAX][MAX] = {0};
    for (i = 0; i < r1; i++) for (j = 0; j < c2; j++)
        for (k = 0; k < c1; k++) result[i][j] += a[i][k] * b[k][j];
    printf("Multiplication:\n"); displayMatrix(result, r1, c2);
}

void transposeMatrix(int a[MAX][MAX], int r, int c)
{
    int i, j;
    printf("Transpose of Matrix A:\n");
    for (j = 0; j < c; j++) { for (i = 0; i < r; i++) printf("%d\t", a[i][j]); printf("\n"); }
}

int main(void)
{
    int a[MAX][MAX], b[MAX][MAX], r1, c1, r2, c2, choice;
    printf("Enter Matrix A\n"); readMatrix(a, &r1, &c1);
    printf("Enter Matrix B\n"); readMatrix(b, &r2, &c2);
    printf("1.Addition  2.Subtraction  3.Multiplication  4.Transpose of A\nChoice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1: if (r1 == r2 && c1 == c2) addMatrix(a,b,r1,c1); else printf("Addition not possible.\n"); break;
        case 2: if (r1 == r2 && c1 == c2) subtractMatrix(a,b,r1,c1); else printf("Subtraction not possible.\n"); break;
        case 3: if (c1 == r2) multiplyMatrix(a,b,r1,c1,c2); else printf("Multiplication not possible.\n"); break;
        case 4: transposeMatrix(a,r1,c1); break;
        default: printf("Invalid choice.\n");
    }
    return 0;
}
