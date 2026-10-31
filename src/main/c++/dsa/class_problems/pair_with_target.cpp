#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

// Approach 1: Hash-based (Optimal Time)
bool hasPairWithSum(const vector<int>& nums, int target) {
    unordered_set<int> seen;
    for (int num : nums) {
        int complement = target - num;
        if (seen.count(complement)) {
            return true;
        }
        seen.insert(num);
    }
    return false;
}