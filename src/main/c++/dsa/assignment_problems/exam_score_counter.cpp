#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to count scores within the band [low, high] inclusive
int countInBand(const vector<int>& scores, int low, int high) {
    // lower_bound finds the first element that is >= low
    auto left_it = lower_bound(scores.begin(), scores.end(), low);
    
    // upper_bound finds the first element that is strictly > high
    auto right_it = upper_bound(scores.begin(), scores.end(), high);
    
    // The difference between the two iterators gives the exact count
    return distance(left_it, right_it);
}

int main() {
    vector<int> scores = {35, 42, 42, 50, 58, 58, 58, 63, 71, 88};
    
    // Sample 1
    int low1 = 42, high1 = 58;
    cout << "Sample 1 Output: " << countInBand(scores, low1, high1) << "\n"; // Expected: 6
    
    // Sample 2
    int low2 = 90, high2 = 100;
    cout << "Sample 2 Output: " << countInBand(scores, low2, high2) << "\n"; // Expected: 0
    
    return 0;
}