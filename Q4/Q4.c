
#include <stdio.h>
#include <time.h>

#define DISTRICTS 38
#define MONTHS 12

float annualTotal[DISTRICTS];
float monthlyAverage[MONTHS];
float stateAverage;

void calculateAnnualTotals(float rain[DISTRICTS][MONTHS])
{
    for (int i = 0; i < DISTRICTS; i++) {
        annualTotal[i] = 0;

        for (int j = 0; j < MONTHS; j++) {
            annualTotal[i] += rain[i][j];
        }
    }
}

void calculateMonthlyAverages(float rain[DISTRICTS][MONTHS])
{
    float total = 0;

    for (int j = 0; j < MONTHS; j++) {
        float sum = 0;

        for (int i = 0; i < DISTRICTS; i++) {
            sum += rain[i][j];
        }

        monthlyAverage[j] = sum / DISTRICTS;
        total += sum;
    }

    stateAverage = total / (DISTRICTS * MONTHS);
}

void findWettestMonth(float rain[DISTRICTS][MONTHS])
{
    float maximum = rain[0][0];
    int district = 0, month = 0;

    for (int i = 0; i < DISTRICTS; i++) {
        for (int j = 0; j < MONTHS; j++) {
            if (rain[i][j] > maximum) {
                maximum = rain[i][j];
                district = i;
                month = j;
            }
        }
    }

    printf("\nWettest district: %d", district + 1);
    printf("\nWettest month: %d", month + 1);
    printf("\nMaximum rainfall: %.2f mm\n", maximum);
}

void findDeficientDistricts(void)
{
    printf("\nDistricts below 60%% of state average:\n");

    int found = 0;

    for (int i = 0; i < DISTRICTS; i++) {
        float districtAverage = annualTotal[i] / MONTHS;

        if (districtAverage < 0.60f * stateAverage) {
            printf("District %d: %.2f mm\n",
                   i + 1, districtAverage);
            found = 1;
        }
    }

    if (!found)
        printf("No deficient districts found.\n");
}

void measureTraversalTime(void)
{
    static int a[2000][2000];
    volatile long long sum = 0;
    clock_t start, end;

    // Row-wise traversal
    start = clock();

    for (int i = 0; i < 2000; i++) {
        for (int j = 0; j < 2000; j++) {
            sum += a[i][j];
        }
    }

    end = clock();
    printf("\nRow-wise time: %.6f seconds",
           (double)(end - start) / CLOCKS_PER_SEC);

    // Column-wise traversal
    start = clock();

    for (int j = 0; j < 2000; j++) {
        for (int i = 0; i < 2000; i++) {
            sum += a[i][j];
        }
    }

    end = clock();
    printf("\nColumn-wise time: %.6f seconds\n",
           (double)(end - start) / CLOCKS_PER_SEC);
}

int main(void)
{
    float rain[DISTRICTS][MONTHS];

    printf("Enter rainfall data for 38 districts and 12 months:\n");

    for (int i = 0; i < DISTRICTS; i++) {
        for (int j = 0; j < MONTHS; j++) {
            scanf("%f", &rain[i][j]);
        }
    }

    calculateAnnualTotals(rain);

    calculateMonthlyAverages(rain);

    printf("\nAnnual Rainfall of Each District:\n");

    for (int i = 0; i < DISTRICTS; i++) {
        printf("District %d: %.2f mm\n",
               i + 1, annualTotal[i]);
    }

    printf("\nMonthly State Average Rainfall:\n");

    for (int j = 0; j < MONTHS; j++) {
        printf("Month %d: %.2f mm\n",
               j + 1, monthlyAverage[j]);
    }

    printf("\nOverall State Monthly Average: %.2f mm\n",
           stateAverage);

    findWettestMonth(rain);
    findDeficientDistricts();

    measureTraversalTime();

    return 0;
}
