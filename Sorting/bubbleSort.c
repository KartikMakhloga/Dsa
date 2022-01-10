#include <stdio.h>

void printArray(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", A[i]);
    }
    printf("\n");
}

void bubbleSort(int *A, int n)
{
    int temp, isSorted = 0;
    for (int i = 0; i < n - 1; i++)
    {
        printf("\n doing %d pass\n", i + 1);
        for (int j = 0; j < n - 1 - i; j++)
        {
            isSorted = 1;
            if (A[j] > A[j + 1])
            {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
                isSorted = 0;
            }
            printArray(A, n);
        }
        if (isSorted)
        {
            break;
        }
    }
}

int main()
{
    int n;
    printf("how many elements you want to enter in array ");
    scanf("%d", &n);
    int A[n];
    printf("enter elements of array ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    printf("\n\nprinting array \n");
    printArray(A, n);
    bubbleSort(A, n);
    printf("\n\nsorted array ");
    printArray(A, n);
    return 0;
}