#include <iostream>
#include <vector>
#include <algorithm>

int maxSubArray(const std::vector<int>& nums) {
    int currentSum = nums[0];
    int maxSum = nums[0];

    for (size_t i = 1; i < nums.size(); ++i) {
        // Extend existing running subarray OR start fresh at current element
        currentSum = std::max(nums[i], currentSum + nums[i]);
        maxSum = std::max(maxSum, currentSum);
    }

    return maxSum;
}

int main() {
    std::vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    std::cout << "Output 1: " << maxSubArray(nums1) << "\n"; // 6

    std::vector<int> nums2 = {-3, -1, -2};
    std::cout << "Output 2: " << maxSubArray(nums2) << "\n"; // -1

    return 0;
}