#include <string.h>
#include <stdio.h>
#include <ctype.h>

void reverseString(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void removeNonAlphanumeric(char* str) {
    int len = strlen(str);
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (isalnum(str[i])) {
            str[j++] = tolower(str[i]);
        }
    }
    str[j] = '\0';
}

int countVowels(char* str) {
    int count = 0;
    for (int i = 0; str[i]; i++) {
        switch (tolower(str[i])) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                count++;
                break;
        }
    }
    return count;
}

int main() {
    char input[100];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove trailing newline

    reverseString(input);
    removeNonAlphanumeric(input);

    printf("Reversed and cleaned string: %s\n", input);
    printf("Number of vowels: %d\n", countVowels(input));

    return 0;
}
