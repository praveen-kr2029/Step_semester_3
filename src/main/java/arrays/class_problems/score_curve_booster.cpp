#include <iostream>
#include <vector>

// Helper to format vector output similar to Java's Arrays.toString()
void printVector(const std::vector<int>& vec) {
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i + 1 < vec.size()) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

// Curve scores directly in-place
void curveScores(std::vector<int>& scores, int bonus) {
    for (int& score : scores) {
        score += bonus;
    }
}

int main() {
    std::vector<int> scores = {70, 85, 60};
    curveScores(scores, 10);
    printVector(scores); // Output: [80, 95, 70]
    
    return 0;
}