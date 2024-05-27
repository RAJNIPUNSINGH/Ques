#include <stdio.h>

int isPrime(int num) {
    if (num <= 1) {
        return 0; 
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0; 
        }
    }
    return 1; 
}

int main() {
    int num1, num2;

    
    scanf("%d", &num1);
    scanf("%d", &num2);

    
    if (num1 > num2) {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }

    
    for (int i = num1; i <= num2; i++) {
        if (isPrime(i)) {
            printf("%d\n", i);
        }
    }

    return 0;
}
