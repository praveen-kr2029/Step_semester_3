#include <iostream>
#include <vector>
#include <string>

std::string findDuplicateTeam(const std::vector<std::string>& teamNames) {
    int n = teamNames.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (teamNames[i] == teamNames[j]) {
                return "Duplicate Found: " + teamNames[i];
            }
        }
    }
    return "No Duplicates Found";
}

int main() {
    std::vector<std::string> test1 = {"ByteForce", "CodeCrafters", "ByteForce"};
    std::cout << findDuplicateTeam(test1) << std::endl; // Output: Duplicate Found: ByteForce

    std::vector<std::string> test2 = {"ByteForce", "CodeCrafters", "NullPointers"};
    std::cout << findDuplicateTeam(test2) << std::endl; // Output: No Duplicates Found

    return 0;
}