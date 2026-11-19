
#include <stdio.h>
#include <time.h>

#define MAX_CANDIDATES 12
#define MAX_VOTES 500000

int main(void)
{
    int votes[MAX_VOTES];
    int count[MAX_CANDIDATES + 1] = {0};

    int candidates, totalVotes;
    int valid = 0, invalid = 0;

    printf("Enter number of candidates (maximum 12): ");
    scanf("%d", &candidates);

    if (candidates < 1 || candidates > MAX_CANDIDATES) {
        printf("Invalid candidate count.\n");
        return 1;
    }

    printf("Enter total number of votes: ");
    scanf("%d", &totalVotes);

    if (totalVotes < 1 || totalVotes > MAX_VOTES) {
        printf("Invalid vote count.\n");
        return 1;
    }

    printf("Enter votes (candidate numbers):\n");

    for (int i = 0; i < totalVotes; i++) {
        scanf("%d", &votes[i]);
    }

    // Count valid and invalid votes
    clock_t start = clock();

    for (int i = 0; i < totalVotes; i++) {
        if (votes[i] >= 1 && votes[i] <= candidates) {
            count[votes[i]]++;
            valid++;
        }
        else {
            invalid++;
        }
    }

    clock_t end = clock();

    // Display vote details
    printf("\nElection Results\n");
    printf("------------------------\n");

    printf("Valid votes: %d\n", valid);
    printf("Invalid votes: %d\n", invalid);

    // Sort candidates by descending vote count
    int order[MAX_CANDIDATES];

    for (int i = 0; i < candidates; i++) {
        order[i] = i + 1;
    }

    for (int i = 0; i < candidates - 1; i++) {
        for (int j = 0; j < candidates - i - 1; j++) {
            if (count[order[j]] < count[order[j + 1]]) {
                int temp = order[j];
                order[j] = order[j + 1];
                order[j + 1] = temp;
            }
        }
    }

    printf("\nCandidate Vote Details:\n");

    for (int i = 0; i < candidates; i++) {
        printf("Candidate %d: %d votes\n",
               order[i], count[order[i]]);
    }

    // Find maximum votes
    int maximum = count[1];

    for (int i = 2; i <= candidates; i++) {
        if (count[i] > maximum)
            maximum = count[i];
    }

    // Check tie
    int winners = 0;

    for (int i = 1; i <= candidates; i++) {
        if (count[i] == maximum)
            winners++;
    }

    if (winners > 1) {
        printf("\nElection Result: TIE\n");
        printf("Winning candidates:\n");

        for (int i = 1; i <= candidates; i++) {
            if (count[i] == maximum)
                printf("Candidate %d\n", i);
        }
    }
    else {
        for (int i = 1; i <= candidates; i++) {
            if (count[i] == maximum) {
                printf("\nWinner: Candidate %d\n", i);
                break;
            }
        }
    }

    printf("\nCounting execution time: %.6f seconds\n",
           (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}
