#include <iostream>
#include <string>
#include <algorithm>

// Approach 1: Iterative Comparison
bool isPalindromeIterative(const std::string& text) {
    int left = 0;
    int right = text.length() - 1;
    while (left < right) {
        if (text[left] != text[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

// Helper function for recursive approach
bool isPalindromeRecursiveHelper(const std::string& text, int left, int right) {
    if (left >= right) {
        return true;
    }
    if (text[left] != text[right]) {
        return false;
    }
    return isPalindromeRecursiveHelper(text, left + 1, right - 1);
}

// Approach 2: Recursion
bool isPalindromeRecursive(const std::string& text) {
    return isPalindromeRecursiveHelper(text, 0, text.length() - 1);
}

// Approach 3: Array (String) Reversal
bool isPalindromeArrayReversal(const std::string& text) {
    std::string reversedText = text;
    std::reverse(reversedText.begin(), reversedText.end());
    return text == reversedText;
}

void testPalindrome(const std::string& text) {
    bool iter = isPalindromeIterative(text);
    bool recur = isPalindromeRecursive(text);
    bool rev = isPalindromeArrayReversal(text);

    std::cout << "Input: \"" << text << "\"\n";
    std::cout << "Iterative: " << (iter ? "Palindrome" : "Not Palindrome")
              << " | Recursive: " << (recur ? "Palindrome" : "Not Palindrome")
              << " | Array Reversal: " << (rev ? "Palindrome" : "Not Palindrome") << "\n\n";
}

int main() {
    testPalindrome("madam");
    testPalindrome("hello");
    return 0;
}