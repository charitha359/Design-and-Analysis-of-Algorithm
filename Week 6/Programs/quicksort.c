#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

/* Partition using LAST element */
int partitionLast(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

/* FIRST element as pivot */
int partitionFirst(int arr[], int low, int high) {
    swap(&arr[low], &arr[high]);
    return partitionLast(arr, low, high);
}

/* RANDOM pivot */
int partitionRandom(int arr[], int low, int high) {
    int r = low + rand() % (high - low + 1);
    swap(&arr[r], &arr[high]);
    return partitionLast(arr, low, high);
}

void quickSort(int arr[], int low, int high, int choice) {
    if (low < high) {
        int p;

        switch (choice) {
            case 1:
                p = partitionFirst(arr, low, high);
                break;
            case 2:
                p = partitionLast(arr, low, high);
                break;
            case 3:
                p = partitionRandom(arr, low, high);
                break;
            default:
                return;
        }

        quickSort(arr, low, p - 1, choice);
        quickSort(arr, p + 1, high, choice);
    }
}

int main() {
    srand(time(NULL));

    int choice;

    do {
        printf("\n QUICK SORT MENU \n");
        printf("1. Quick Sort (First Pivot)\n");
        printf("2. Quick Sort (Last Pivot)\n");
        printf("3. Quick Sort (Random Pivot)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 3) {
            int n;
            printf("Enter number of elements: ");
            scanf("%d", &n);

            int arr[n];
            printf("Enter elements (space separated):\n");
            for (int i = 0; i < n; i++)
                scanf("%d", &arr[i]);

            quickSort(arr, 0, n - 1, choice);

            printf("Sorted array:\n");
            for (int i = 0; i < n; i++)
                printf("%d ", arr[i]);
            printf("\n");
        }
        else if (choice == 4) {
            printf("Exiting program...\n");
        }
        else {
            printf("Invalid choice! Try again.\n");
        }

    } while (choice != 4);

    return 0;
}
