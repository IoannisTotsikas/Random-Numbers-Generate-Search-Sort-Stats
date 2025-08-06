#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100

// Bubble sort function to sort the array in ascending order
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // swap arr[j] and arr[j + 1]
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Print the array elements in rows of 10
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%3d ", arr[i]);
        if ((i + 1) % 10 == 0)
            printf("\n");
    }
    if (n % 10 != 0)
        printf("\n");
}

// Search for a number in the array
// Returns index if found, -1 if not found
int searchNumber(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[MAX_SIZE];
    int N;
    int sum, max, min;
    double average;
    int choice;
    int target, position;

    // Initialize random seed
    srand(time(NULL));

    do {
        // Ask user for array size between 20 and 100
        do {
            printf("Enter array size (20-100): ");
            scanf("%d", &N);
        } while (N < 20 || N > MAX_SIZE);

        sum = 0;

        // Generate random numbers and find sum, min, max
        printf("\nRandom numbers generated:\n");
        for (int i = 0; i < N; i++) {
            arr[i] = rand() % 100;  // number between 0 and 99
            printf("%3d ", arr[i]);

            sum += arr[i];

            if (i == 0) {
                max = min = arr[i];
            } else {
                if (arr[i] > max) max = arr[i];
                if (arr[i] < min) min = arr[i];
            }

            if ((i + 1) % 10 == 0)
                printf("\n");
        }
        if (N % 10 != 0)
            printf("\n");

        average = (double)sum / N;

        // Show stats
        printf("\nArray size: %d\n", N);
        printf("Sum: %d\n", sum);
        printf("Max: %d\n", max);
        printf("Min: %d\n", min);
        printf("Average: %.2f\n", average);

        // Search a number input by user
        printf("\nEnter number to search: ");
        scanf("%d", &target);
        position = searchNumber(arr, N, target);
        if (position != -1) {
            printf("Number %d found at index %d.\n", target, position);
        } else {
            printf("Number %d not found.\n", target);
        }

        // Sort the array
        bubbleSort(arr, N);

        // Print sorted array
        printf("\nSorted array:\n");
        printArray(arr, N);

        // Ask if user wants to run again
        printf("\nRun again? (1 = yes, 0 = no): ");
        scanf("%d", &choice);

        printf("\n---------------------------\n\n");

    } while (choice == 1);

    printf("Program finished. Goodbye!\n");

    return 0;
}

