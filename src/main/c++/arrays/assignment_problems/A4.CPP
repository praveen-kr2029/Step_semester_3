#include <iostream>
#include <vector>
#include <unordered_map>

int subarraySum(const std::vector<int>& nums, int k) {
    std::unordered_map<int, int> prefixCounts;
    prefixCounts[0] = 1; // Base case: prefix sum of 0 appears once before array starts

    int currentSum = 0;
    int count = 0;

    for (int num : nums) {
        currentSum += num;

        // Check if there exists a previous prefix sum such that currentSum - prefixSum = k
        if (prefixCounts.find(currentSum - k) != prefixCounts.end()) {
            count += prefixCounts[currentSum - k];
        }

        prefixCounts[currentSum]++;
    }

    return count;
}

int main() {
    std::vector<int> nums1 = {1, 1, 1};
    std::cout << "Output 1: " << subarraySum(nums1, 2) << "\n"; // 2

    std::vector<int> nums2 = {1, -1, 0};
    std::cout << "Output 2: " << subarraySum(nums2, 0) << "\n"; // 3

    return 0;
}