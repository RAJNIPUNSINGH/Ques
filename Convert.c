#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    printf("Enter the number of characters in the string: ");
    scanf("%d", &N);

    char *array = (char *)malloc(N * sizeof(char));
    printf("Enter the array of characters: ");
    for (int i = 0; i < N; i++) {
        scanf(" %c", &array[i]);
    }

    char *str = (char *)malloc((N + 1) * sizeof(char)); 
    for (int i = 0; i < N; i++) {
        str[i] = array[i];
    }
    str[N] = '\0'; 

    printf("Converted String: %s\n", str);


    return 0;
}
