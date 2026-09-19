#include <iostream>
#include <string>

class PiggyBank {
private:
    const std::string id;
    double savings;

public:
    PiggyBank(const std::string& bank_id) : id(bank_id), savings(0.0) {}

    void deposit(double amount) {
        if (amount > 0) {
            savings += amount;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= savings) {
            savings -= amount;
        }
    }

    double getSavings() const {
        return savings;
    }

    std::string getId() const {
        return id;
    }
};

// Usage Example
void testPiggyBank() {
    PiggyBank pb("PB-1");
    pb.deposit(100);
    std::cout << "Savings: " << pb.getSavings() << "\n"; // 100
    pb.withdraw(30);
    std::cout << "Savings: " << pb.getSavings() << "\n"; // 70
    pb.withdraw(500); // Rejected
    std::cout << "Savings: " << pb.getSavings() << "\n"; // 70
}