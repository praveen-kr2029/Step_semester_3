#include <iostream>
#include <string>

class PayrollAccount {
private:
    double basicSalary;
    double bonus;

public:
    PayrollAccount(double openingSalary) : bonus(0.0) {
        if (openingSalary < 0) {
            std::cout << "Warning: Opening salary cannot be negative. Setting to 0." << std::endl;
            basicSalary = 0;
        } else {
            basicSalary = openingSalary;
        }
    }

    void creditBonus(double amount) {
        if (amount <= 0) {
            std::cout << "Error: Bonus amount must be positive." << std::endl;
        } else {
            bonus += amount;
            std::cout << "Bonus credited: Rs " << amount << std::endl;
        }
    }

    void deductTax(double percent) {
        if (percent < 0 || percent > 100) {
            std::cout << "Error: Tax percentage must be between 0 and 100." << std::endl;
        } else {
            basicSalary -= (basicSalary * percent / 100.0);
            std::cout << "Tax deducted: " << percent << "%" << std::endl;
        }
    }

    double getNetSalary() const {
        return basicSalary + bonus;
    }
};

int main() {
    PayrollAccount account(50000.0);
    account.creditBonus(5000.0);
    account.deductTax(10.0);

    std::cout << "Net salary: Rs " << account.getNetSalary() << std::endl;

    return 0;
}