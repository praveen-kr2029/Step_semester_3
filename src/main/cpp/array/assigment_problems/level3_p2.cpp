#include <iostream>
#include <string>
#include <vector>

void atmPinRetry(const std::string& correctPin, const std::vector<std::string>& attempts) {
    size_t attemptCounter = 0;
    bool pinAccepted = false;

    // Loop continues while attempts remain and success hasn't occurred
    while (attemptCounter < attempts.size() && attemptCounter < 3 && !pinAccepted) {
        if (attempts[attemptCounter] == correctPin) {
            pinAccepted = true;
            std::cout << "PIN accepted\n";
            break;
        }
        attemptCounter++;
    }

    if (!pinAccepted) {
        std::cout << "Card blocked — too many incorrect attempts\n";
    }
}

int main() {
    // Test Case 1
    std::cout << "Input 1:\nOutput: ";
    atmPinRetry("4821", {"1111", "4821"});

    // Test Case 2
    std::cout << "\nInput 2:\nOutput: ";
    atmPinRetry("4821", {"1111", "2222", "3333"});

    return 0;
}