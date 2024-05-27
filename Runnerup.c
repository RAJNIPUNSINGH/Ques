#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of participants: ");
    scanf("%d", &n);

    int A[n];
    printf("Enter the scores of the participants: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    int max = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }

    int runnerUp = -100;
    for (int i = 0; i < n; i++) {
        if (A[i] != max && A[i] > runnerUp) {
            runnerUp = A[i];
        }
    }

    printf("The runner-up score is: %d\n", runnerUp);

    return 0;
}
