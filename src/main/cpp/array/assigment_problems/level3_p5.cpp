#include <iostream>
#include <vector>

void guessTheNumber(int secretNumber, int maxTries, const std::vector<int>& guesses) {
    size_t tryCounter = 0;
    bool guessedCorrectly = false;

    while (tryCounter < maxTries && tryCounter < guesses.size() && !guessedCorrectly) {
        int currentGuess = guesses[tryCounter];

        if (currentGuess > secretNumber) {
            std::cout << "Too high ";
        } else if (currentGuess < secretNumber) {
            std::cout << "Too low ";
        } else {
            std::cout << "Correct! You guessed it\n";
            guessedCorrectly = true;
            break;
        }

        tryCounter++;
    }

    if (!guessedCorrectly) {
        std::cout << "Out of tries — the number was " << secretNumber << "\n";
    }
}

int main() {
    // Test Case 1
    std::cout << "Test Case 1:\nOutput: ";
    guessTheNumber(42, 4, {20, 60, 42});

    // Test Case 2
    std::cout << "\nTest Case 2:\nOutput: ";
    guessTheNumber(42, 2, {10, 15});

    return 0;
}