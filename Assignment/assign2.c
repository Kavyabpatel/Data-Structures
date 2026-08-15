#include <stdio.h>

// Recursive function to find the smallest number in an array
int findSmallest(int arr[], int n) {
    // Base case: only one element left
    if (n == 1)
        return arr[0];

    // Recursive case: compare first element with smallest of the rest
    int smallOfRest = findSmallest(arr + 1, n - 1);

    return (arr[0] < smallOfRest) ? arr[0] : smallOfRest;
}

int main() {
    int arr[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Smallest element is: %d\n", findSmallest(arr, n));

    return 0;
}

