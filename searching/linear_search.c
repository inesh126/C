#include <stdio.h>
#include <stdlib.h>

int linearsearch(int *arr, int size, int val)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == val)
            return i;  // Return index if found
    }
    return -1;  // Not found
}

void printArray(int *arr, int size)
{
    printf("Array contents: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the size of the array:\n");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid array size!\n");
        return 1;
    }

    int *a = (int *)malloc(n * sizeof(int));
    if (a == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printArray(a, n);

    char choice;
    do
    {
        int v;
        printf("Enter the value to be searched:\n");
        scanf("%d", &v);

        int index = linearsearch(a, n, v);
        if (index != -1)
            printf("Value %d is in the array at index %d.\n", v, index);
        else
            printf("Value %d is not in the array.\n", v);

        printf("Search again? (y/n): ");
        scanf(" %c", &choice);  // The space before %c eats the leftover newline
    } while (choice == 'y' || choice == 'Y');

    free(a);
    return 0;
}
