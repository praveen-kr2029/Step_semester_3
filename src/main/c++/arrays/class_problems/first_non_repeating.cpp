#include <iostream>
#include <string>
#include <unordered_map>

char findFirstNonRepeatingChar(const std::string& text) {
    std::unordered_map<char, int> frequency;

    // Step 1: Count occurrences of each character
    for (char ch : text) {
        frequency[ch]++;
    }

    // Step 2: Scan string left to right to find the first character with a count of 1
    for (char ch : text) {
        if (frequency[ch] == 1) {
            return ch;
        }
    }

    // Return null character if no non-repeating character is found
    return '\0';
}

void processInput(const std::string& text) {
    std::cout << "Input: \"" << text << "\"\n";
    char result = findFirstNonRepeatingChar(text);
    
    if (result != '\0') {
        std::cout << "First Non-Repeating Character: '" << result << "'\n\n";
    } else {
        std::cout << "No Non-Repeating Character Found\n\n";
    }
}

int main() {
    processInput("swiss");
    processInput("aabbcc");
    return 0;
}