#include <stdio.h>

int smallestMultiple(int n, int k) {
    int remainder = n % k;
    
    if (remainder == 0) {
        return n + k;
    } else {
        return (n / k + 1) * k;
    }
}

int main() {
    int n, k;

    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Enter the value of k: ");
    scanf("%d", &k);

    int result = smallestMultiple(n, k);

    printf("%d", result);

    return 0;
}
