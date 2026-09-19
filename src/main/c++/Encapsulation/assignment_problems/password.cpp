#include <iostream>
#include <string>

class PasswordChecker {
private:
    const std::string password;

public:
    PasswordChecker(const std::string& pwd) : password(pwd) {}

    std::string getStrength() const {
        int len = password.length();
        if (len < 6) return "Weak";
        if (len <= 9) return "Medium";
        return "Strong";
    }
    
    // No getter is provided for the password itself.
};

// Usage Example
void testPasswordChecker() {
    PasswordChecker pc("abcd");
    std::cout << "Strength: " << pc.getStrength() << "\n"; // Weak
    
    PasswordChecker pc2("abcdefghij");
    std::cout << "Strength: " << pc2.getStrength() << "\n"; // Strong
}