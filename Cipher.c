#include <stdio.h>

char cipher(char ch, int k) {
    if (ch >= 'a' && ch <= 'z') {
        return 'a' + (ch - 'a' + k) % 26;
    } else if (ch >= 'A' && ch <= 'Z') {
        return 'A' + (ch - 'A' + k) % 26;
    } else {
        return ch; 
    }
}

char CaesarCipher(char *s, int k) {
    for (int i = 0; s[i] != '\0'; i++) {
        s[i] = cipher(s[i], k);
    }
}

int main() {
    int n, k;
    printf("Enter the length of the string: "); 
    scanf("%d", &n);

    char s[n]; 
    printf("Enter the unencrypted string: ");
    scanf("%s", s);

    printf("Enter k: ");
    scanf("%d", &k);

    CaesarCipher(s, k);

    printf("ciphered string: %s\n", s);

    return 0;
}
