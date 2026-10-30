
#include <stdio.h>

struct Student
{
    int roll;
    char name[30];
};

struct Student s[100];
int n;

// Function to input students
void input()
{
    int i;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter roll number and name: ");
        scanf("%d %29s", &s[i].roll, s[i].name);
    }
}

// Function to display students
void display()
{
    int i;

    printf("\nRoll No\tName\n");

    for (i = 0; i < n; i++)
    {
        printf("%d\t%s\n", s[i].roll, s[i].name);
    }
}

// Linear Search
void linearSearch()
{
    int key, i;

    printf("Enter roll number to search: ");
    scanf("%d", &key);

    for (i = 0; i < n; i++)
    {
        if (s[i].roll == key)
        {
            printf("Student found: %s\n", s[i].name);
            return;
        }
    }

    printf("Student not found.\n");
}

// Insertion Sort
void insertionSort()
{
    int i, j;
    struct Student temp;

    for (i = 1; i < n; i++)
    {
        temp = s[i];
        j = i - 1;

        while (j >= 0 && s[j].roll > temp.roll)
        {
            s[j + 1] = s[j];
            j--;
        }

        s[j + 1] = temp;
    }

    printf("Insertion Sort completed.\n");
}

// Selection Sort
void selectionSort()
{
    int i, j, min;
    struct Student temp;

    for (i = 0; i < n - 1; i++)
    {
        min = i;

        for (j = i + 1; j < n; j++)
        {
            if (s[j].roll < s[min].roll)
            {
                min = j;
            }
        }

        temp = s[i];
        s[i] = s[min];
        s[min] = temp;
    }

    printf("Selection Sort completed.\n");
}

// Shell Sort
void shellSort()
{
    int gap, i, j;
    struct Student temp;

    for (gap = n / 2; gap > 0; gap = gap / 2)
    {
        for (i = gap; i < n; i++)
        {
            temp = s[i];
            j = i;

            while (j >= gap && s[j - gap].roll > temp.roll)
            {
                s[j] = s[j - gap];
                j = j - gap;
            }

            s[j] = temp;
        }
    }

    printf("Shell Sort completed.\n");
}

// Binary Search
void binarySearch()
{
    int key, low, high, mid;

    printf("Enter roll number to search: ");
    scanf("%d", &key);

    low = 0;
    high = n - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (s[mid].roll == key)
        {
            printf("Student found: %s\n", s[mid].name);
            return;
        }
        else if (s[mid].roll < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    printf("Student not found.\n");
}

// Main function
int main()
{
    int choice;

    input();

    while (1)
    {
        printf("\n--- STUDENT DATABASE ---\n");
        printf("1. Display Students\n");
        printf("2. Linear Search\n");
        printf("3. Insertion Sort\n");
        printf("4. Selection Sort\n");
        printf("5. Shell Sort\n");
        printf("6. Binary Search\n");
        printf("7. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            display();
        }
        else if (choice == 2)
        {
            linearSearch();
        }
        else if (choice == 3)
        {
            insertionSort();
        }
        else if (choice == 4)
        {
            selectionSort();
        }
        else if (choice == 5)
        {
            shellSort();
        }
        else if (choice == 6)
        {
            binarySearch();
        }
        else if (choice == 7)
        {
            printf("Program ended.\n");
            break;
        }
        else
        {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}
