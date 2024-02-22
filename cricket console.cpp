#include <stdio.h>

// Define a structure to represent a cricket match
struct CricketMatch {
    char teamName[50];
    int score;
};

// Function to write match data to a file
void writeToFile(struct CricketMatch matches[], int numMatches, const char *filename) {
    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < numMatches; ++i) {
        fprintf(file, "%s %d\n", matches[i].teamName, matches[i].score);
    }

    fclose(file);
}

// Function to read match data from a file
void readFromFile(struct CricketMatch matches[], int *numMatches, const char *filename) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    *numMatches = 0;

    while (fscanf(file, "%s %d", matches[*numMatches].teamName, &matches[*numMatches].score) == 2) {
        (*numMatches)++;
    }

    fclose(file);
}

// Function to display match statistics
void displayStatistics(struct CricketMatch matches[], int numMatches) {
    int totalScore = 0;
    float averageScore;

    for (int i = 0; i < numMatches; ++i) {
        totalScore += matches[i].score;
    }

    averageScore = (float)totalScore / numMatches;

    printf("\nMatch Statistics:\n");
    printf("Total Matches: %d\n", numMatches);
    printf("Total Score: %d\n", totalScore);
    printf("Average Score: %.2f\n", averageScore);
}

// Function to print scores
void printScores(struct CricketMatch matches[], int numMatches) {
    printf("\nMatch Scores:\n");
    for (int i = 0; i < numMatches; ++i) {
        printf("Match %d: %s %d\n", i + 1, matches[i].teamName, matches[i].score);
    }
}

// Function to show match result
void showResult(struct CricketMatch match) {
    printf("\nMatch Result:\n");
    printf("%s scored %d runs.\n", match.teamName, match.score);
}

// Function to update match score
void updateScore(struct CricketMatch *match, int newScore) {
    match->score = newScore;
}

int main() {
    const char *filename = "cricket_scores.txt";
    struct CricketMatch matches[3];  // Array of structures for three matches
    int numMatches;

    // Read data from the file or initialize if the file doesn't exist
    readFromFile(matches, &numMatches, filename);

    // Example: Update the score for match 2
    updateScore(&matches[1], 180);

    // Write the updated data to the file
    writeToFile(matches, numMatches, filename);

    // Display match statistics, scores, and result
    displayStatistics(matches, numMatches);
    printScores(matches, numMatches);
    showResult(matches[1]);

    return 0;
}



