#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    vector<int> nums(n);
    int even = 0, odd = 0;
    
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        if (nums[i] % 2 == 0) {
            even++;
        } else {
            odd++;
        }
    }
    
    cout << "Even: " << even << "\n";
    cout << "Odd: " << odd << "\n";
    
    return 0;
}