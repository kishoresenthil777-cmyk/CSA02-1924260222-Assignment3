
#include <stdio.h>

/* Merge two descending-order merit lists */
int merge(const int a[], int na, const int b[], int nb, int out[])
{
    int i = 0, j = 0, k = 0;

    /* Compare both lists and copy the larger score */
    while (i < na && j < nb)
    {
        if (a[i] >= b[j])
            out[k++] = a[i++];
        else
            out[k++] = b[j++];
    }

    /* Copy remaining elements of list A */
    while (i < na)
        out[k++] = a[i++];

    /* Copy remaining elements of list B */
    while (j < nb)
        out[k++] = b[j++];

    return k;
}

int main(void)
{
    int campusA[] = {98, 91, 85, 72};
    int campusB[] = {95, 91, 80};
    int merged[7];

    int n = merge(campusA, 4, campusB, 3, merged);

    printf("Merged Merit List:\n");

    for (int i = 0; i < n; i++)
        printf("%d ", merged[i]);

    printf("\n");

    return 0;
}
