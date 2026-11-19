
#include <stdio.h>

#define N 10

int comparisons, swaps;

void bubble_sort(int a[], int n)
{
    comparisons = swaps = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int flag = 0;

        for (int j = 0; j < n - i - 1; j++)
        {
            comparisons++;

            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                swaps++;
                flag = 1;
            }
        }

        if (flag == 0)
            break;
    }
}

void selection_sort(int a[], int n)
{
    comparisons = swaps = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int min = i;

        for (int j = i + 1; j < n; j++)
        {
            comparisons++;

            if (a[j] < a[min])
                min = j;
        }

        if (min != i)
        {
            int temp = a[i];
            a[i] = a[min];
            a[min] = temp;
            swaps++;
        }
    }
}

void insertion_sort(int a[], int n)
{
    comparisons = swaps = 0;

    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;

        while (j >= 0)
        {
            comparisons++;

            if (a[j] > key)
            {
                a[j + 1] = a[j];
                swaps++;
                j--;
            }
            else
                break;
        }

        a[j + 1] = key;
    }
}

void test_sort(char name[], int original[], int n)
{
    int a[N];

    printf("\n%s\n", name);

    for (int i = 0; i < n; i++)
        a[i] = original[i];

    bubble_sort(a, n);
    printf("Bubble Sort: Comparisons = %d, Swaps = %d\n",
           comparisons, swaps);

    for (int i = 0; i < n; i++)
        a[i] = original[i];

    selection_sort(a, n);
    printf("Selection Sort: Comparisons = %d, Swaps = %d\n",
           comparisons, swaps);

    for (int i = 0; i < n; i++)
        a[i] = original[i];

    insertion_sort(a, n);
    printf("Insertion Sort: Comparisons = %d, Shifts = %d\n",
           comparisons, swaps);
}

int main(void)
{
    int sorted[N] = {10,20,30,40,50,60,70,80,90,100};
    int nearly[N] = {10,20,30,40,50,60,70,80,100,90};
    int reverse[N] = {100,90,80,70,60,50,40,30,20,10};
    int random[N] = {40,10,80,30,90,20,70,50,100,60};

    test_sort("Sorted Array", sorted, N);
    test_sort("Nearly Sorted Array", nearly, N);
    test_sort("Reverse Sorted Array", reverse, N);
    test_sort("Random Array", random, N);

    return 0;
}
