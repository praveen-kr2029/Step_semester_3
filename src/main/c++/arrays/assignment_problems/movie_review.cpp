#include <iostream>
#include <string>
#include <sstream>

void classifyWordLengths(const std::string& review) {
    std::stringstream ss(review);
    std::string word;

    int shortCount = 0;
    int mediumCount = 0;
    int longCount = 0;

    while (ss >> word) {
        int len = word.length();
        if (len >= 1 && len <= 4) {
            shortCount++;
        } else if (len >= 5 && len <= 8) {
            mediumCount++;
        } else if (len >= 9) {
            longCount++;
        }
    }

    std::cout << "Short: " << shortCount 
              << " | Medium: " << mediumCount 
              << " | Long: " << longCount << "\n";
}

int main() {
    std::string review = "This movie was absolutely fantastic and thrilling";
    classifyWordLengths(review);
    return 0;
}