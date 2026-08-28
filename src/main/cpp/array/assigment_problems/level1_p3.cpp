#include <iostream>

void printNumbersUpToN(int n) {
    // Loop counter starts at 1 and runs until it reaches n
    for (int i = 1; i <= n; ++i) {
        std::cout << i << " ";
    }
    std::cout << "\n";
}

int main() {
    std::cout << "Input: n = 5\nOutput: ";
    printNumbersUpToN(5);

    return 0;
}