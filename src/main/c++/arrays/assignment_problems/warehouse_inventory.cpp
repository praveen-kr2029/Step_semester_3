#include <iostream>
#include <vector>
#include <string>

void analyzeInventory(const std::vector<int>& sectionA, const std::vector<int>& sectionB) {
    int sumA = 0;
    int sumB = 0;

    int maxQuantity = -1;
    std::string maxSection = "";
    int maxIndex = -1;

    int n = sectionA.size();

    for (int i = 0; i < n; ++i) {
        sumA += sectionA[i];
        sumB += sectionB[i];

        if (sectionA[i] > maxQuantity) {
            maxQuantity = sectionA[i];
            maxSection = "Section A";
            maxIndex = i + 1; // 1-based item indexing
        }

        if (sectionB[i] > maxQuantity) {
            maxQuantity = sectionB[i];
            maxSection = "Section B";
            maxIndex = i + 1; // 1-based item indexing
        }
    }

    std::string status = (sumA == sumB) ? "Balanced" : "Not Balanced";

    std::cout << "Section A Total: " << sumA 
              << " | Section B Total: " << sumB 
              << " | Status: " << status 
              << " | Highest Quantity: " << maxQuantity 
              << " (" << maxSection << ", Item " << maxIndex << ")\n";
}

int main() {
    std::vector<int> sectionA = {20, 15, 30};
    std::vector<int> sectionB = {25, 10, 30};

    analyzeInventory(sectionA, sectionB);
    return 0;
}