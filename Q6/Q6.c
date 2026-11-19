
#include <stdio.h>
#include <string.h>

#define MAX_NAMES 5000
#define SIZE 30

int main(void)
{
    char names[MAX_NAMES][SIZE];
    char temp[SIZE], search[SIZE];
    int n, comparisons = 0, copies = 0;
    int found = 0;

    printf("Enter number of names: ");
    scanf("%d", &n);
    getchar();

    if (n < 1 || n > MAX_NAMES) {
        printf("Invalid number of names.\n");
        return 1;
    }

    printf("Enter %d names:\n", n);

    for (int i = 0; i < n; i++) {
        if (fgets(names[i], SIZE, stdin) == NULL)
            return 1;

        names[i][strcspn(names[i], "\n")] = '\0';
    }

    // Bubble sort using strcmp and strcpy
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;

            if (strcmp(names[j], names[j + 1]) > 0) {
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
                copies += 3;
            }
        }
    }

    printf("\nNames in alphabetical order:\n");

    for (int i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }

    printf("\nDuplicate names:\n");

    for (int i = 1; i < n; i++) {
        if (strcmp(names[i], names[i - 1]) == 0) {
            printf("%s\n", names[i]);
            found = 1;
        }
    }

    if (!found)
        printf("No duplicates found.\n");

    printf("\nEnter name to search: ");

    if (fgets(search, SIZE, stdin) == NULL)
        return 1;

    search[strcspn(search, "\n")] = '\0';

    // Binary search
    int low = 0, high = n - 1, pos = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        comparisons++;

        int result = strcmp(names[mid], search);

        if (result == 0) {
            pos = mid;
            break;
        }
        else if (result < 0) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    if (pos != -1)
        printf("Name found at index %d\n", pos);
    else
        printf("Name not found.\n");

    printf("\nTotal strcmp comparisons: %d\n", comparisons);
    printf("Total string copies during sorting: %d\n", copies);

    return 0;
}
