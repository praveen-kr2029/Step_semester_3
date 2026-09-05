#include <iostream>
#include <vector>
#include <string>

// Helper method to compute average of a single row
double rowAverage(const std::vector<int>& row) {
    if (row.empty()) return 0.0;
    
    double sum = 0.0;
    for (int score : row) {
        sum += score;
    }
    return sum / row.size();
}

// Classification method using rowAverage helper
std::string classifyRows(const std::vector<std::vector<int>>& seatingScores, int threshold) {
    std::string result = "";
    
    for (size_t i = 0; i < seatingScores.size(); ++i) {
        double avg = rowAverage(seatingScores[i]);
        
        std::string zone = (avg < threshold) ? "Quiet Zone" : "Buzzing Zone";
        result += "Row " + std::to_string(i) + ": " + zone;
        
        if (i + 1 < seatingScores.size()) {
            result += " | ";
        }
    }
    
    return result;
}

int main() {
    std::vector<std::vector<int>> seatingScores = {
        {40, 50, 45},
        {85, 90, 95},
        {30, 20, 25}
    };
    int threshold = 60;

    std::cout << classifyRows(seatingScores, threshold) << std::endl;
    // Output: Row 0: Quiet Zone | Row 1: Buzzing Zone | Row 2: Quiet Zone

    return 0;
}