#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to rotate the roster to the right by k places
vector<string> rotateRoster(const vector<string>& names, long long k) {
    int n = names.size();
    if (n == 0) return names;
    
    // Effective rotations after removing full cycles
    k = k % n;
    
    vector<string> rotated(n);
    for (int i = 0; i < n; ++i) {
        // Each element at index i moves to (i + k) % n
        int new_index = (i + k) % n;
        rotated[new_index] = names[i];
    }
    
    return rotated;
}

int main() {
    // Sample 1
    vector<string> names = {"A", "B", "C", "D", "E"};
    long long k1 = 2;
    vector<string> result1 = rotateRoster(names, k1);
    
    cout << "Sample 1 Output: [";
    for (size_t i = 0; i < result1.size(); ++i) {
        cout << result1[i] << (i == result1.size() - 1 ? "" : ", ");
    }
    cout << "]\n"; // Expected: [D, E, A, B, C]
    
    // Sample 2
    long long k2 = 7;
    vector<string> result2 = rotateRoster(names, k2);
    
    cout << "Sample 2 Output: [";
    for (size_t i = 0; i < result2.size(); ++i) {
        cout << result2[i] << (i == result2.size() - 1 ? "" : ", ");
    }
    cout << "]\n"; // Expected: [D, E, A, B, C]
    
    return 0;
}