#include <iostream>
#include <string>

class Locker {
private:
    const int lockerNumber;
    std::string code;

public:
    Locker(int number, const std::string& initialCode) 
        : lockerNumber(number), code(initialCode) {}

    bool changeCode(const std::string& currentCode, const std::string& newCode) {
        if (currentCode == code) {
            code = newCode;
            return true;
        }
        return false;
    }

    int getLockerNumber() const {
        return lockerNumber;
    }
};

// Usage Example
void testLocker() {
    Locker l(101, "1234");
    
    bool s1 = l.changeCode("1234", "5678");
    std::cout << "First change success: " << (s1 ? "true" : "false") << "\n"; // true
    
    bool s2 = l.changeCode("0000", "9999");
    std::cout << "Second change success: " << (s2 ? "true" : "false") << "\n"; // false
}