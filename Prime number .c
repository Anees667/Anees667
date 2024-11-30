#include <stdio.h>
#include <stdbool.h>

bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void find_primes_in_range(int start, int end) {
    FILE *file = fopen("primes.txt", "w"); // Open a file in write mode
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    for (int i = start; i <= end; i++) {
        if (is_prime(i)) {
            fprintf(file, "%d\n", i);  // Write each prime number to the file
        }
    }

    fclose(file);  // Close the file
    printf("Prime numbers have been saved to primes.txt\n");
}

int main() {
    int start, end;

    printf("Enter the start of the range: ");
    scanf("%d", &start);
    printf("Enter the end of the range: ");
    scanf("%d", &end);

    find_primes_in_range(start, end);

    return 0;
}
