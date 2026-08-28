#include <iostream>

void printSkippingMultiplesOfThree() {
    for (int i = 1; i <= 20; ++i) {
        // Skip current iteration if i is divisible by 3
        if (i % 3 == 0) {
            continue;
        }
        std::cout << i << " ";
    }
    std::cout << "\n";
}

int main() {
    std::cout << "Output: ";
    printSkippingMultiplesOfThree();

    return 0;
}