#include <stdio.h>
#include <string.h>  // For strlen()

// Ensures the first character is in uppercase, lowercases the rest (ASCII)
void capitalize_name(char name[]) {
    int len = strlen(name);

    if (name[0] >= 'a' && name[0] <= 'z') {
        name[0] -= 32; // Convert to uppercase
    }

    for (int i = 1; i < len; i++) {
        if (name[i] >= 'A' && name[i] <= 'Z') {
            name[i] += 32; // Convert to lowercase
        }
    }
}

int main() {
    const int NUM_STUDENTS = 5;
    const int NUM_TESTS = 13;
    const int NAME_LENGTH = 11;

    char names[NUM_STUDENTS][NAME_LENGTH];
    int scores[NUM_STUDENTS][NUM_TESTS];
    float averages[NUM_STUDENTS];
    float total_average = 0.0;

    // Names and test scores
    for (int i = 0; i < NUM_STUDENTS; i++) {
        scanf("%s", names[i]);

        int sum = 0;
        for (int j = 0; j < NUM_TESTS; j++) {
            scanf("%d", &scores[i][j]);
            sum += scores[i][j];
        }

        averages[i] = (float)sum / NUM_TESTS;
        total_average += averages[i];
    }

    total_average /= NUM_STUDENTS;

    // Calculates index of student with the highest average
    int top_index = 0;
    for (int i = 1; i < NUM_STUDENTS; i++) {
        if (averages[i] > averages[top_index]) {
            top_index = i;
        }
    }

    // Print top student
    capitalize_name(names[top_index]);
    printf("%s\n", names[top_index]);

    // Print students with below-average performance
    for (int i = 0; i < NUM_STUDENTS; i++) {
        if (averages[i] < total_average) {
            capitalize_name(names[i]);
            printf("%s\n", names[i]);
        }
    }



    return 0;
}
