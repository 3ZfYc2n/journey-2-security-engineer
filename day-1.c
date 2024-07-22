#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold name and height
typedef struct {
    char* name;
    int height;
} Person;

// Comparator function for qsort
int compare(const void* a, const void* b) {
    return ((Person*)b)->height - ((Person*)a)->height;
}

char** sortPeople(char** names, int namesSize, int* heights, int heightsSize, int* returnSize) {
    // Ensure the sizes match
    if (namesSize != heightsSize) {
        *returnSize = 0;
        return NULL;
    }

    // Allocate memory for an array of Person structures
    Person* people = (Person*)malloc(namesSize * sizeof(Person));
    if (!people) {
        *returnSize = 0;
        return NULL;
    }

    // Combine names and heights into the array of Person structures
    for (int i = 0; i < namesSize; ++i) {
        people[i].name = names[i];
        people[i].height = heights[i];
    }

    // Sort the array using qsort and the comparator function
    qsort(people, namesSize, sizeof(Person), compare);

    // Allocate memory for the sorted names array
    char** sortedNames = (char**)malloc(namesSize * sizeof(char*));
    if (!sortedNames) {
        free(people);
        *returnSize = 0;
        return NULL;
    }

    // Extract sorted names
    for (int i = 0; i < namesSize; ++i) {
        sortedNames[i] = people[i].name;
    }

    // Free the allocated memory for people array
    free(people);

    // Set the return size
    *returnSize = namesSize;

    return sortedNames;
}

// Helper function to print the sorted names
void printSortedNames(char** sortedNames, int size) {
    for (int i = 0; i < size; ++i) {
        printf("%s ", sortedNames[i]);
    }
    printf("\n");
}

int main() {
    char* names[] = {"Mary", "John", "Emma"};
    int heights[] = {180, 165, 170};
    int namesSize = 3;
    int heightsSize = 3;
    int returnSize;

    char** sortedNames = sortPeople(names, namesSize, heights, heightsSize, &returnSize);

    if (sortedNames) {
        printSortedNames(sortedNames, returnSize);
        free(sortedNames); // Free the allocated memory for sorted names
    } else {
        printf("Error: Sorting failed or memory allocation error.\n");
    }

    return 0;
}
