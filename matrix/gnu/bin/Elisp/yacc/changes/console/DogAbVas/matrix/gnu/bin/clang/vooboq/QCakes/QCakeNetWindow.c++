#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#if 0
int main() {
    // Define the input string
    char input_string[] = "Hello, World!";
    
    // Create a copy of the input string
    char *copy_string = malloc(strlen(input_string) + 1);
    if (copy_string == NULL) {
        fprintf(stderr, "Error: Out of memory\n");
        return 1;
    }
    strcpy(copy_string, input_string);
    
    // Reverse the copied string
    int length = strlen(copy_string);
    for (int i = 0; i < length / 2; i++) {
        char temp = copy_string[i];
        copy_string[i] = copy_string[length - 1 - i];
        copy_string[length - 1 - i] = temp;
    }
    
    // Print the reversed string
    printf("Reversed string: %s\n",
    copy_string);

    // Free the allocated memory
    free(copy_string);
    
    return 0;
}
#endif
