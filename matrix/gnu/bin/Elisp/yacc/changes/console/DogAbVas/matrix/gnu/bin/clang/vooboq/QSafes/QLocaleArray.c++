#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#define MAX_ELEMENTS 1000000
#define MAX_WORD_LENGTH 100

#if 0
// Function to check if a character is a vowel
int is_vowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

// Function to count the number of vowels in a given string
int count_vowels(const char* str) {
    int count = 0;
    size_t len = strlen(str);

    for (size_t i = 0; i < len; i++) {
        if (is_vowel(str[i])) {
            count++;
        }
    }

    return count;
}

// Function to count the number of consonants in a given string
int count_consonants(const char* str) {
    int count = 0;
    size_t len = strlen(str);

    for (size_t i = 0; i < len; i++) {
        if (!is_vowel(str[i])) {
            count++;
        }
    }

    return count;
}

// Function to count the number of words in a given string
int count_words(const char* str) {
    int count = 0;
    size_t len = strlen(str);

    for (size_t i = 0; i < len; i++) {
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
            count++;
        }
    }

    // Add one more word for the last word in the string
    count++;

    return count;
}

// Function to split a string into words
void split_words(const char* str, char* words[]) {
    size_t len = strlen(str);
    int word_index = 0;

    for (size_t i = 0; i < len; i++) {
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
            words[word_index][i - word_index] = '\0';
            word_index++;
        } else {
            words[word_index][i - word_index] = str[i];
        }
    }

    words[word_index][len - word_index] = '\0';
}

// Function to sort the words in alphabetical order
void sort_words(char* words[], int num_words) {
    for (int i = 0; i < num_words - 1; i++) {
        for (int j = i + 1; j < num_words; j++) {
            if (strcmp(words[i], words[j]) > 0) {
                char* temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }
}

// Function to remove duplicate words from the array
void remove_duplicates(char* words[], int* num_words) {
    int unique_index = 0;

    for (int i = 0; i < *num_words; i++) {
        int is_duplicate = 0;

        for (int j = 0; j < unique_index; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                is_duplicate = 1;
                break;
            }
        }

        if (!is_duplicate) {
            words[unique_index] = words[i];
            unique_index++;
        }
    }

    *num_words = unique_index;
}

// Function to print the frequency of each word
void print_word_frequency(char* words[], int num_words) {
    int word_frequency[MAX_ELEMENTS] = {0};

    for (int i = 0; i < num_words; i++) {
        word_frequency[i] = count_words(words[i]);
    }

    for (int i = 0; i < num_words; i++) {
        printf("%s: %d\n", words[i], word_frequency[i]);
    }
}

int main() {
    char input_string[MAX_ELEMENTS];
    printf("Enter a string (maximum length %d characters): ", MAX_ELEMENTS);
    fgets(input_string, MAX_ELEMENTS, stdin);

    // Remove newline character from the input string
    input_string[strcspn(input_string, "\n")] = '\0';

    char* words[MAX_ELEMENTS];
    int num_words = 0;

    // Split the input string into words
    split_words(input_string, words);
    num_words = count_words(input_string);

    // Sort the words in alphabetical order
    sort_words(words, num_words);

    // Remove duplicate words from the array
    remove_duplicates(words, &num_words);

    // Print the frequency of each word
    print_word_frequency(words, num_words);

    // Free the dynamically allocated memory for the words array
    for (int
    i = 0; i < num_words; i++) {
        free(words[i]);
    }
    free(words);
    return 0;
}
#endif