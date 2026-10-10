#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to compute attendance summary
void attendanceSummary(const vector<int>& days) {
    int total_present = 0;
    int current_streak = 0;
    int max_streak = 0;
    
    for (int day : days) {
        if (day == 1) {
            total_present++;
            current_streak++;
            max_streak = max(max_streak, current_streak);
        } else {
            current_streak = 0; // Reset streak on absence
        }
    }
    
    cout << "Present: " << total_present << ", Longest streak: " << max_streak << "\n";
}

int main() {
    // Sample 1
    vector<int> days1 = {1, 1, 0, 1, 1, 1, 0, 1};
    cout << "Sample 1 Output: ";
    attendanceSummary(days1); // Expected: Present: 6, Longest streak: 3
    
    // Sample 2
    vector<int> days2 = {0, 0, 0};
    cout << "Sample 2 Output: ";
    attendanceSummary(days2); // Expected: Present: 0, Longest streak: 0
    
    return 0;
}