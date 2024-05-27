#include <stdio.h>

int countOnes(int arr[], int N) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] == 1) {
            count++;
        } 
    }
    return count;
}

int main() {
    int N;
    printf("Enter the size of the array: ");
    scanf("%d", &N);

    int arr[N];
    printf("Enter the binaries: ");
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int onesCount = countOnes(arr, N);
    printf("Number of 1's in the array: %d\n", onesCount);

    return 0;
}
