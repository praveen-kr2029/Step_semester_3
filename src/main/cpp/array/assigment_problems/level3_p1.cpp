#include <iostream>

void printNumberPyramid(int n) {
    // Outer loop controls the current row
    for (int i = 1; i <= n; ++i) {
        // Inner loop prints the row number 'i' times
        for (int j = 1; j <= i; ++j) {
            std::cout << i << " ";
        }
        std::cout << "\n"; // Move to the next line after completing a row
    }
}

int main() {
    std::cout << "Input: n = 4\nOutput:\n";
    printNumberPyramid(4);

    return 0;
}