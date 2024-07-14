#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }

    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            return false;
        }
    }

    return true;
}


// Function to generate all prime numbers up to a given limit
void generatePrimes(int limit) {
    printf("Prime numbers up to %d:\n", limit);

    for (int num = 2; num <= limit; num++) {
        if (isPrime(num)) {
            printf("%d ", num);
        }
    }

    printf("\n");
}


int main() {
    int limit;

    printf("Enter a limit: ");
    scanf("%d", &limit);

    generatePrimes(limit);

    return 0;
}
