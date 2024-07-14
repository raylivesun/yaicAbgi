#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


#if 0
// Function to calculate the length of a string
int string_length(const char* str) {
    int length = 0;
    while (str[length]) {
        length++;
    }
    return length;
}


// Function to reverse a string in-place
void reverse_string(char* str) {
    int length = string_length(str);
    int start = 0;
    int end = length - 1;

    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}


// Function to compare two strings
int string_compare(const char* str1, const char* str2) {
    int length1 = string_length(str1);
    int length2 = string_length(str2);

    if (length1 != length2) {
        return length1 - length2;
    }

    for (int i = 0; i < length1; i++) {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
    }

    return 0;
}


// Function to concatenate two strings
char* string_concat(const char* str1, const char* str2) {
    int length1 = string_length(str1);
    int length2 = string_length(str2);

    char* result = malloc((length1 + length2 + 1) * sizeof(char));
    assert(result != NULL);

    strcpy(result, str1);
    strcat(result, str2);

    return result;
}


// Function to remove all occurrences of a character from a string
char* string_remove_char(const char* str, char target) {
    int length = string_length(str);
    int count = 0;

    for (int i = 0; i < length; i++) {
        if (str[i] != target) {
            count++;
        }
    }

    char* result = malloc((count + 1) * sizeof(char));
    assert(result != NULL);

    int j = 0;
    for (int i = 0; i < length; i++) {
        if (str[i] != target) {
            result[j++] = str[i];
        }
    }
    result[count] = '\0';

    return result;
}


// Function to find the first occurrence of a substring in a string
int string_find_substring(const char* str, const char* substring) {
    int length1 = string_length(str);
    int length2 = string_length(substring);

    for (int i = 0; i <= length1 - length2; i++) {
        int j = 0;
        while (j < length2 && str[i + j] == substring[j]) {
            j++;
        }
        if (j == length2) {
            return i;
        }
    }

    return -1;
}


// Function to find the last occurrence of a substring in a string
int string_find_last_substring(const char* str, const char* substring) {
    int length1 = string_length(str);
    int length2 = string_length(substring);

    for (int i = length1 - length2; i >= 0; i--) {
        int j = 0;
        while (j < length2 && str[i + j] == substring[j]) {
            j++;
        }
        if (j == length2) {
            return i;
        }
    }

    return -1;
}


// Function to find the number of occurrences of a substring in a string
int string_count_substring(const char* str, const char* substring) {
    int count = 0;
    int index = string_find_substring(str, substring);

    while (index != -1) {
        count++;
        index = string_find_substring(str + index + string_length(substring), substring);
    }

    return count;
}


// Function to split a string into an array of substrings based on a delimiter
char** string_split(const char* str, char delimiter, int* count) {
    int length = string_length(str);
    int substrings_count = 1;

    for (int i = 0; i < length; i++) {
        if (str[i] == delimiter) {
            substrings_count++;
        }
    }

    char** substrings = malloc(substrings_count * sizeof(char*));
    assert(substrings != NULL);

    int start = 0;
    int end = 0;
    int substring_index = 0;

    for (int i = 0; i <= length; i++) {
        if (str[i] == delimiter || str[i] == '\0') {
            substrings[substring_index] = malloc((end - start + 1) * sizeof(char));
            assert(substrings[substring_index] != NULL);
            strncpy(
                substrings[substring_index],
                str + start,
                end - start
            );
            substrings[substring_index][end - start] = '\0';
            substring_index++;
            start = i + 1;
            end = i + 1;
            continue;
        }
        end++;
        if (i == length) {
            substrings[substring_index] = malloc((end - start + 1) * sizeof(char));
            assert(substrings[substring_index] != NULL);
            strncpy(
                substrings[substring_index],
                str + start,
                end - start
            );
            substrings[substring_index][end - start] = '\0';
            substring_index++;
        }
        end++;
        if (substring_index == substrings_count) {
            break;
        }
        end++;
        if (i == length) {
            break;
        }
        end++;
        if (substring_index == substrings_count) {
            break;
        }
        end++;
        if (i == length) {
            break;
        }
        end++;
        if (substring_index == substrings_count) {
            break;
        }
        end++;
    }
    *count = substrings_count;
    return substrings;
    // Don't forget to free the allocated memory for substrings when done using them
    // Example:
    // for (int i = 0; i < substrings_count; i++) {
    //     free(substrings[i]);
    // }
    // free(substrings);
}


int main() {
    // Test cases
    char str1[] = "Hello, World!";
    char str2[] = "world";
    char target = 'o';

    printf("Length of string: %d\n", string_length(str1));
    reverse_string(str1);
    printf("Reversed string: %s\n", str1);
    printf("Comparison result: %d\n", string_compare(str1, str2));
    char* concatenated_str = string_concat(str1, " ");
    printf("Concatenated string: %s\n", concatenated_str);
    free(concatenated_str);
    char* removed_char_str = string_remove_char(str1, target);
    printf("String with '%c' removed: %s\n", target, removed_char_str);
    free(removed_char_str);
    int index = string_find_substring(str
    1, "lo");
    printf("First occurrence of 'lo': %d\n", index);
    index = string_find_last_substring(str1, "lo");
    printf("Last occurrence of 'lo': %d\n", index);
    int count;
    char** substrings = string_split(str1, ' ', &count);
    printf("Substrings: ");
    for (int i = 0; i < count; i++) {
        printf("%s ", substrings[i]);
        free(substrings[i]);
    }
    printf("\n");
    free(substrings);
    return 0;
    // Add more test cases as needed
    // Make sure to free the allocated memory for substrings when done using them
}
#endif