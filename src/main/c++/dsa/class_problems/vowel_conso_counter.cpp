#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string word;
    cout << "Enter a word: ";
    cin >> word;
    
    int vowels = 0, consonants = 0;
    for (char c : word) {
        char lower = tolower(c);
        if (isalpha(lower)) {
            if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }
    
    cout << "Vowels: " << vowels << "\n";
    cout << "Consonants: " << consonants << "\n";
    
    return 0;
}