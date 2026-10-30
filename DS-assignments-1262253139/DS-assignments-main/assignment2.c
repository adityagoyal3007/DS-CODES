#include <stdio.h>

void accept(int a[10][10], int m, int n)
{
    int i, j;
    printf("\nEnter the matrix values:\n");
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

void display(int a[10][10], int m, int n)
{
    int i, j;
    printf("\nThe matrix values:\n");
    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("\t%d", a[i][j]);
        }
        printf("\n");
    }
}


void displayTriplet(int a[101][3], int rows)
{
    int i;
    printf("\nRow\tColumn\tValue\n");
    for (i = 0; i < rows; i++)
        printf("%d\t%d\t%d\n", a[i][0], a[i][1], a[i][2]);
}

void compact(int a[10][10], int b[101][3], int m, int n)
{
    int i, j, k = 1;

    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(a[i][j] != 0)
            {
                b[k][0] = i;
                b[k][1] = j;
                b[k][2] = a[i][j];
                k++;
            }
        }
    }

    b[0][0] = m;
    b[0][1] = n;
    b[0][2] = k - 1;

    printf("\nCompact Matrix:");
    displayTriplet(b, b[0][2] + 1);
}

void transpose(int a[101][3], int b[101][3], int n)
{
    int i, j, k;

    b[0][0] = a[0][1];
    b[0][1] = a[0][0];
    b[0][2] = a[0][2];

    k = 1;
    n = a[0][2];

    for(i = 0; i < a[0][1]; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(i == a[j][1])
            {
                b[k][0] = a[j][1];
                b[k][1] = a[j][0];
                b[k][2] = a[j][2];
                k++;
            }
        }
    }
}


void fastTranspose(int a[101][3], int b[101][3])
{
    int count[10] = {0}, position[10] = {0};
    int i, col, terms = a[0][2], cols = a[0][1];

    b[0][0] = a[0][1];
    b[0][1] = a[0][0];
    b[0][2] = terms;

    for (i = 1; i <= terms; i++)
        count[a[i][1]]++;

    position[0] = 1;
    for (col = 1; col < cols; col++)
        position[col] = position[col - 1] + count[col - 1];

    for (i = 1; i <= terms; i++)
    {
        int pos = position[a[i][1]]++;
        b[pos][0] = a[i][1];
        b[pos][1] = a[i][0];
        b[pos][2] = a[i][2];
    }
}

int main()
{
    int a[10][10], triplet[101][3], trans[101][3];
    int m, n, choice;

    printf("Enter number of rows (max 10): ");
    scanf("%d", &m);

    printf("Enter number of columns (max 10): ");
    scanf("%d", &n);
    if (m < 1 || m > 10 || n < 1 || n > 10) { printf("Invalid dimensions.\n"); return 1; }

    printf("\nEnter matrix elements:\n");
    accept(a, m, n);

    printf("\nOriginal Matrix:\n");
    display(a, m, n);

    compact(a, triplet, m, n);

    printf("\nTriplet Matrix:\n");
    displayTriplet(triplet, triplet[0][2] + 1);

    printf("\n1. Simple Transpose\n2. Fast Transpose\nEnter choice: ");
    scanf("%d", &choice);
    if (choice == 1)
    {
        transpose(triplet, trans, n);
        printf("\nSimple Transpose:\n");
        displayTriplet(trans, trans[0][2] + 1);
    }
    else if (choice == 2)
    {
        fastTranspose(triplet, trans);
        printf("\nFast Transpose:\n");
        displayTriplet(trans, trans[0][2] + 1);
    }
    else printf("Invalid choice.\n");

    return 0;
}



















