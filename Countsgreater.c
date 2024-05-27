#include <stdio.h>

int Greater(int arr[], int length, int num) {
    int count = 0;
    for (int i = 0; i < length; i++) {
        if (arr[i] > num) {
            count++;
        }
    }
    return count;
}

int main() {
    int length;
    printf("Enter the length of the array: ");
    scanf("%d", &length);

    int arr[length];
    printf("Enter the array elements: ");
    for (int i = 0; i < length; i++) {
        scanf("%d", &arr[i]);
    }

    int num;
    printf("Enter the number for comparison: ");
    scanf("%d", &num);

    int count = Greater(arr, length, num);
    printf("Count of numbers greater than %d: %d\n", num, count);

    return 0;
}
