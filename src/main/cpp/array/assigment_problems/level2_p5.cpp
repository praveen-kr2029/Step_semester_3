#include <iostream>

void checkPrime(int number) {
    bool isPrime = true;

    if (number <= 1) {
        isPrime = false;
    } else {
        // Check divisibility from 2 up to number / 2
        for (int i = 2; i <= number / 2; ++i) {
            if (number % i == 0) {
                isPrime = false;
                break; // Factor found, stop checking further
            }
        }
    }

    if (isPrime) {
        std::cout << "Prime\n";
    } else {
        std::cout << "Not Prime\n";
    }
}

int main() {
    // Test Case 1
    std::cout << "Input: number = 17\nOutput: ";
    checkPrime(17);

    // Test Case 2
    std::cout << "\nInput: number = 18\nOutput: ";
    checkPrime(18);

    return 0;
}