#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::vector<std::vector<int>> result;
    int n = nums.size();
    
    // Step 1: Sort the array
    std::sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 2; ++i) {
        // Skip duplicate outer elements
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        
        // Optimization: Smallest element > 0 means sum will always be > 0
        if (nums[i] > 0) break;

        int left = i + 1;
        int right = n - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum == 0) {
                result.push_back({nums[i], nums[left], nums[right]});

                // Skip duplicate values on left and right
                while (left < right && nums[left] == nums[left + 1]) ++left;
                while (left < right && nums[right] == nums[right - 1]) --right;

                ++left;
                --right;
            } else if (sum < 0) {
                ++left;
            } else {
                --right;
            }
        }
    }

    return result;
}

int main() {
    std::vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    auto res1 = threeSum(nums1);
    std::cout << "Output 1:\n";
    for (const auto& triplet : res1) {
        std::cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]\n";
    }

    std::vector<int> nums2 = {0, 0, 0};
    auto res2 = threeSum(nums2);
    std::cout << "Output 2:\n";
    for (const auto& triplet : res2) {
        std::cout << "[" << triplet[0] << ", " << triplet[1] << ", " << triplet[2] << "]\n";
    }

    return 0;
}