#include <iostream>
#include <vector>

std::vector<int> productExceptSelf(const std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> answer(n, 1);

    // Pass 1: Compute running product of elements to the left
    int leftRunningProduct = 1;
    for (int i = 0; i < n; ++i) {
        answer[i] = leftRunningProduct;
        leftRunningProduct *= nums[i];
    }

    // Pass 2: Compute running product of elements to the right and combine
    int rightRunningProduct = 1;
    for (int i = n - 1; i >= 0; --i) {
        answer[i] *= rightRunningProduct;
        rightRunningProduct *= nums[i];
    }

    return answer;
}

int main() {
    std::vector<int> nums1 = {1, 2, 3, 4};
    std::vector<int> result1 = productExceptSelf(nums1);
    
    std::cout << "Output 1: ";
    for (int val : result1) std::cout << val << " "; // 24 12 8 6
    std::cout << "\n";

    std::vector<int> nums2 = {-1, 1, 0, -3, 3};
    std::vector<int> result2 = productExceptSelf(nums2);
    
    std::cout << "Output 2: ";
    for (int val : result2) std::cout << val << " "; // 0 0 9 0 0
    std::cout << "\n";

    return 0;
}