#include <iostream>

void classifyNumber(int number) {
    // Check if the number is greater than zero
    if (number > 0) {
        std::cout << "Positive\n";
    } 
    // Check if the number is less than zero
    else if (number < 0) {
        std::cout << "Negative\n";
    } 
    // If it is neither greater nor less than zero, it must be zero
    else {
        std::cout << "Zero\n";
    }
}

int main() {
    // Test Case 1
    std::cout << "Input: number = 15\nOutput: ";
    classifyNumber(15);

    // Test Case 2
    std::cout << "\nInput: number = -4\nOutput: ";
    classifyNumber(-4);

    // Test Case 3
    std::cout << "\nInput: number = 0\nOutput: ";
    classifyNumber(0);

    return 0;
}