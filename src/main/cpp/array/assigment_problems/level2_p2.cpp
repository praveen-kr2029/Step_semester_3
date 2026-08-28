#include <iostream>
#include <string>
#include <vector>

void simulateLogin(const std::string& correctCode, const std::vector<std::string>& attempts) {
    bool accessGranted = false;

    for (size_t i = 0; i < attempts.size() && i < 3; ++i) {
        if (attempts[i] == correctCode) {
            std::cout << "Access granted on attempt " << (i + 1) << "\n";
            accessGranted = true;
            break; // Exit loop immediately upon successful match
        }
    }

    if (!accessGranted) {
        std::cout << "Access denied — all attempts used\n";
    }
}

int main() {
    // Test Case 1
    std::cout << "Input 1:\nOutput: ";
    simulateLogin("1234", {"0000", "1234", "9999"});

    // Test Case 2
    std::cout << "\nInput 2:\nOutput: ";
    simulateLogin("1234", {"1111", "2222", "3333"});

    return 0;
}