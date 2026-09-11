#include <iostream>
#include <vector>
#include <string>

std::string findMinMaxSpread(const std::vector<int>& scores) {
    int minVal = scores[0];
    int maxVal = scores[0];

    for (size_t i = 1; i < scores.size(); ++i) {
        if (scores[i] < minVal) {
            minVal = scores[i];
        }
        if (scores[i] > maxVal) {
            maxVal = scores[i];
        }
    }

    int spread = maxVal - minVal;
    return "Min: " + std::to_string(minVal) + 
           " | Max: " + std::to_string(maxVal) + 
           " | Spread: " + std::to_string(spread);
}

int main() {
    std::vector<int> scores = {45, 82, 79, 90, 33, 90, 61};
    std::cout << findMinMaxSpread(scores) << std::endl;
    return 0;
}