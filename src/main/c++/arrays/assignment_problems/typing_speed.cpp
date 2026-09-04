#include <iostream>
#include <string>
#include <iomanip>

void checkTypingAccuracy(const std::string& original, const std::string& typed) {
    int total = original.length();
    int matches = 0;
    int firstMismatch = -1;

    for (int i = 0; i < total; ++i) {
        if (original[i] == typed[i]) {
            matches++;
        } else if (firstMismatch == -1) {
            firstMismatch = i; // Save the 0-indexed position of the first mismatch
        }
    }

    double accuracy = (static_cast<double>(matches) / total) * 100.0;

    std::cout << "Matched: " << matches << "/" << total 
              << " | Accuracy: " << std::fixed << std::setprecision(2) << accuracy << "%";

    if (firstMismatch != -1) {
        std::cout << " | First Mismatch at position " << (firstMismatch + 1) 
                  << " ('" << original[firstMismatch] << "' vs '" << typed[firstMismatch] << "')\n";
    } else {
        std::cout << " | No Mismatches\n";
    }
}

int main() {
    checkTypingAccuracy("hello world", "hello worlt");
    checkTypingAccuracy("coding", "coding");
    return 0;
}