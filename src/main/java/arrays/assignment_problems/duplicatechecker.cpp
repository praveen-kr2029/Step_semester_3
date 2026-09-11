#include <iostream>
#include <vector>
#include <string>

std::string findDuplicatePick(const std::vector<std::string>& playerNames) {
    int n = playerNames.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (playerNames[i] == playerNames[j]) {
                return "Duplicate Found: " + playerNames[i];
            }
        }
    }
    return "No Duplicates Found";
}

int main() {
    std::vector<std::string> lineup1 = {"Kohli", "Bumrah", "Kohli", "Rohit"};
    std::vector<std::string> lineup2 = {"Kohli", "Bumrah", "Rohit"};

    std::cout << findDuplicatePick(lineup1) << std::endl; // Output: Duplicate Found: Kohli
    std::cout << findDuplicatePick(lineup2) << std::endl; // Output: No Duplicates Found

    return 0;
}