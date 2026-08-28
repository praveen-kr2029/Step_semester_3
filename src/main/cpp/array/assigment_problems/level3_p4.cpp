#include <iostream>
#include <vector>

void generateFirstValidTable(const std::vector<int>& candidates) {
    for (int num : candidates) {
        // Skip non-positive values
        if (num < 1) {
            std::cout << "Skipping invalid number: " << num << "\n";
            continue;
        }

        // Print multiplication table for first valid number found
        for (int i = 1; i <= 10; ++i) {
            std::cout << num << " x " << i << " = " << (num * i) << "\n";
        }
        break; // Stop checking further candidates once a table is printed
    }
}

int main() {
    std::cout << "Input: candidates = {-3, 0, 7, 9}\nOutput:\n";
    generateFirstValidTable({-3, 0, 7, 9});

    return 0;
}