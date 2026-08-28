#include <iostream>

void calculate(double a, double b, char op) {
    switch (op) {
        case '+':
            std::cout << "Result: " << (a + b) << "\n";
            break;
        case '-':
            std::cout << "Result: " << (a - b) << "\n";
            break;
        case '*':
            std::cout << "Result: " << (a * b) << "\n";
            break;
        case '/':
            if (b == 0) {
                std::cout << "Cannot divide by zero\n";
            } else {
                std::cout << "Result: " << (a / b) << "\n";
            }
            break;
        default:
            std::cout << "Invalid operator\n";
            break;
    }
}

int main() {
    // Test Case 1
    std::cout << "Input: a = 10, b = 4, op = '+'\nOutput: ";
    calculate(10, 4, '+');

    // Test Case 2
    std::cout << "\nInput: a = 10, b = 0, op = '/'\nOutput: ";
    calculate(10, 0, '/');

    // Test Case 3
    std::cout << "\nInput: a = 10, b = 4, op = '%'\nOutput: ";
    calculate(10, 4, '%');

    return 0;
}