#include <stdalign.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Allocate memory for a 100-element array of doubles
    double *array = (double *)aligned_alloc(alignof(double), sizeof(double) * 100);
    if (array == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory.\n");
        return 1;
    }

    // Initialize the array with random values
    for (int i = 0; i < 100; i++) {
        array[i] = (double)rand() / RAND_MAX;
    }

    // Calculate the sum of the array elements using SIMD instructions
    double sum = 0.0;
    for (int i = 0; i < 100; i += 4) {
        double *vec = (double *)(&array
        [i]);  // Convert the array index to a pointer to the first element of the SIMD vector
        sum += vec[0] + vec[1] + vec[2] + vec[3];
        // Repeat for the remaining elements in the vector
        if (i + 4 < 100) {
            vec = (double *)(&array[i + 4]);
            sum += vec[0] + vec[1] + vec[2] + vec[3];
        }
    }
    printf("Sum of array elements: %.2f\n", sum);

    // Deallocate the memory
    free(array);

    return 0;
}

