#include <iostream>

using namespace std;

int main() {
    long long num;
    cout << "Enter a positive integer: ";
    cin >> num;
    
    long long sum = 0;
    long long reverse_num = 0;
    long long temp = num;
    
    while (temp > 0) {
        long long digit = temp % 10;
        sum += digit;
        reverse_num = reverse_num * 10 + digit;
        temp /= 10;
    }
    
    cout << "Sum of digits: " << sum << "\n";
    cout << "Reverse: " << reverse_num << "\n";
    
    return 0;
}