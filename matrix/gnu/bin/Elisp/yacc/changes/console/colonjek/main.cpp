#include <string.h>
#include <stdio.h>

int main() {
    char str1[] = "Hello, World!";
    char str2[] = "Hello";
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // Check if the strings are equal
    if (len1 != len2) {
        printf("Strings are not equal\n");
        return 0;
    }

    // Compare the characters of the strings
    int i;
    for (i = 0; i < len1; i++) {
        if (str1[i] != str2[i]) {
            printf("Strings are not equal\n");
            return 0;
        }
    }

    printf("Strings are equal\n");
    return 0;
}
