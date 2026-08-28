#include <iostream>

void checkVotingEligibility(int age) {
    // Build the boolean expression
    bool isEligible = (age >= 18);

    // Single if / else statement based on the boolean result
    if (isEligible) {
        std::cout << "Eligible to vote\n";
    } else {
        std::cout << "Not eligible to vote\n";
    }
}

int main() {
    // Test Case 1
    std::cout << "Input: age = 20\nOutput: ";
    checkVotingEligibility(20);

    // Test Case 2
    std::cout << "\nInput: age = 16\nOutput: ";
    checkVotingEligibility(16);

    return 0;
}