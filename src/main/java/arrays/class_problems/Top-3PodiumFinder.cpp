#include <iostream>
#include <vector>
#include <climits>

std::vector<int> findTopThreeScores(const std::vector<int>& scores) {
    int first = INT_MIN;
    int second = INT_MIN;
    int third = INT_MIN;

    for (int score : scores) {
        if (score >= first) {
            third = second;
            second = first;
            first = score;
        } else if (score >= second) {
            third = second;
            second = score;
        } else if (score > third) {
            third = score;
        }
    }

    return {first, second, third};
}

int main() {
    std::vector<int> scores = {45, 82, 79, 90, 33, 90, 61};
    std::vector<int> podium = findTopThreeScores(scores);

    std::cout << "[" << podium[0] << ", " << podium[1] << ", " << podium[2] << "]" << std::endl;
    // Output: [90, 90, 82]

    return 0;
}