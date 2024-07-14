#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>


// Function to find the number of set bits in a given number
uint8_t countSetBits(uint32_t n) {
    uint8_t count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

// Function to find the number of 1s between two given numbers
uint32_t countOnesBetween(uint32_t n, uint32_t m) {
    uint32_t xorResult = n ^ m;
    return countSetBits(xorResult);
}

int main() {
    uint32_t n, m;

    printf("Enter two 32-bit numbers: ");
    scanf("%u %u", &n, &m);

    uint32_t count = countOnesBetween(n, m);
    printf("Number of 1s between %u and %u: %u\n", n, m, count);

    return 0;
}
