#include <stdio.h>
#include <string.h>

int countSubstring(char *string, char *substring) {
    int count = 0;
    int stringLen = strlen(string);
    int subLen = strlen(substring);

    for (int i = 0; i <= stringLen - subLen; i++) {
        int j;
        for (j = 0; j < subLen; j++) {
            if (string[i + j] != substring[j]) {
                break;
            }
        }
        if (j == subLen) {
            count++;
        }
    }

    return count;
}

int main() {
    char string[201]; 
    char substring[201];

    printf("Enter the original string: ");
    scanf("%s", string);

    printf("Enter the substring: ");
    scanf("%s", substring);

    int occurrences = countSubstring(string, substring);
    printf("Number of occurrences of the substring: %d\n", occurrences);

    return 0;
}
