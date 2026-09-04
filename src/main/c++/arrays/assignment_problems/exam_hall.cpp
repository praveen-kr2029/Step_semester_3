#include <iostream>
#include <vector>

void checkDuplicateSeats(const std::vector<int>& seatNumbers) {
    int n = seatNumbers.size();
    bool foundDuplicate = false;

    // Using nested loops without any Collections/HashMaps
    for (int i = 0; i < n; ++i) {
        // Check if we already processed this seat number to avoid duplicate print statements
        bool alreadyPrinted = false;
        for (int k = 0; k < i; ++k) {
            if (seatNumbers[i] == seatNumbers[k]) {
                alreadyPrinted = true;
                break;
            }
        }
        if (alreadyPrinted) continue;

        // Search for duplicates ahead in the array
        for (int j = i + 1; j < n; ++j) {
            if (seatNumbers[i] == seatNumbers[j]) {
                std::cout << "Duplicate Seat Number Found: " << seatNumbers[i] << "\n";
                foundDuplicate = true;
                break;
            }
        }
    }

    if (!foundDuplicate) {
        std::cout << "No Duplicate Seats Found\n";
    }
}

int main() {
    std::vector<int> test1 = {101, 102, 103, 102, 105};
    std::cout << "Input 1:\n";
    checkDuplicateSeats(test1);

    std::cout << "\nInput 2:\n";
    std::vector<int> test2 = {101, 102, 103, 104, 105};
    checkDuplicateSeats(test2);

    return 0;
}