#include <iostream>
#include <vector>

int findMin(const std::vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[right]) {
            // Minimum must be in the right unsorted section
            left = mid + 1;
        } else {
            // Minimum is at mid or in the left section
            right = mid;
        }
    }

    return nums[left];
}

int main() {
    std::vector<int> nums1 = {3, 4, 5, 1, 2};
    std::cout << "Output 1: " << findMin(nums1) << "\n"; // 1

    std::vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    std::cout << "Output 2: " << findMin(nums2) << "\n"; // 0

    std::vector<int> nums3 = {11, 13, 15, 17};
    std::cout << "Output 3: " << findMin(nums3) << "\n"; // 11

    return 0;
}