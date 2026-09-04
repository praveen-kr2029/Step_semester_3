#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>

std::string getBmiStatus(double bmi) {
    if (bmi < 18.5) {
        return "Underweight";
    } else if (bmi < 25.0) {
        return "Normal";
    } else if (bmi < 30.0) {
        return "Overweight";
    } else {
        return "Obese";
    }
}

void printWellnessReport(const std::vector<double>& heights, const std::vector<double>& weights) {
    std::cout << std::left 
              << std::setw(10) << "Person" 
              << std::setw(14) << "| Height (m)" 
              << std::setw(14) << "| Weight (kg)" 
              << std::setw(10) << "| BMI" 
              << "| Status\n";
    std::cout << "---------------------------------------------------------\n";

    for (size_t i = 0; i < heights.size(); ++i) {
        double bmi = weights[i] / (heights[i] * heights[i]);
        std::string status = getBmiStatus(bmi);

        std::cout << std::left 
                  << std::setw(10) << ("Person " + std::to_string(i + 1))
                  << "| " << std::setw(12) << std::fixed << std::setprecision(2) << heights[i]
                  << "| " << std::setw(12) << std::fixed << std::setprecision(1) << weights[i]
                  << "| " << std::setw(8)  << std::fixed << std::setprecision(2) << bmi
                  << "| " << status << "\n";
    }
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    int teamSize = 10;
    std::vector<double> heights(teamSize);
    std::vector<double> weights(teamSize);

    // Generating realistic random heights (1.50m - 1.90m) and weights (50kg - 100kg)
    for (int i = 0; i < teamSize; ++i) {
        heights[i] = 1.50 + (std::rand() % 41) / 100.0;
        weights[i] = 50.0 + (std::rand() % 51);
    }

    printWellnessReport(heights, weights);

    return 0;
}