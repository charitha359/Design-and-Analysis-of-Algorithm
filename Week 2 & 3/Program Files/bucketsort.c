#include <stdio.h>

void bucketSort(int a[], int n) {
    int i, j;
    int max = a[0];

    for (i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];

    int bucket[max + 1];

    for (i = 0; i <= max; i++)
        bucket[i] = 0;

    for (i = 0; i < n; i++)
        bucket[a[i]]++;

    j = 0;
    for (i = 0; i <= max; i++)
        while (bucket[i] > 0) {
            a[j++] = i;
            bucket[i]--;
        }
}

int main() {
    int n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    bucketSort(a, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}

