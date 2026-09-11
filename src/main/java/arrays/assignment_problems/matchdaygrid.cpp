#include <iostream>
#include <vector>
#include <string>

// Helper function to calculate row average
double rowAverage(const std::vector<int>& row) {
    double sum = 0;
    for (int runs : row) {
        sum += runs;
    }
    return sum / row.size();
}

std::string classifyMatches(const std::vector<std::vector<int>>& runsPerOver, int threshold) {
    std::string result = "";
    for (size_t i = 0; i < runsPerOver.size(); ++i) {
        double avg = rowAverage(runsPerOver[i]);
        std::string status = (avg >= threshold) ? "Power Surge" : "Normal";
        
        result += "Match " + std::to_string(i) + ": " + status;
        if (i < runsPerOver.size() - 1) {
            result += " | ";
        }
    }
    return result;
}

int main() {
    std::vector<std::vector<int>> runsPerOver = {
        {4, 6, 8},
        {10, 12, 14},
        {2, 3, 1}
    };
    int threshold = 8;

    std::cout << classifyMatches(runsPerOver, threshold) << std::endl;
    return 0;
}