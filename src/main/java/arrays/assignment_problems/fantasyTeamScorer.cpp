#include <iostream>
#include <vector>
#include <string>

// Modifies the original vector directly using reference parameters
void applyMultipliers(std::vector<double>& playerScores, int captainIndex, int viceCaptainIndex) {
    playerScores[captainIndex] *= 2.0;
    playerScores[viceCaptainIndex] *= 1.5;
}

int main() {
    std::vector<double> scores = {40, 55, 30, 62};
    applyMultipliers(scores, 1, 3);

    // Format output as [40.0, 110.0, 30.0, 93.0]
    std::cout << "[";
    for (size_t i = 0; i < scores.size(); ++i) {
        std::cout << scores[i] << (i == scores.size() - 1 ? "" : ", ");
    }
    std::cout << "]" << std::endl;

    return 0;
}