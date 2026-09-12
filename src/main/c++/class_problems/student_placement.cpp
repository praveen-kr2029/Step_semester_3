#include <iostream>

class MessWallet {
private:
    double balance;

public:
    // Constructor with negative balance check
    MessWallet(double openingBalance) {
        if (openingBalance < 0) {
            std::cout << "Warning: Opening balance cannot be negative. Initialized to 0.0\n";
            this->balance = 0.0;
        } else {
            this->balance = openingBalance;
        }
    }

    void topUp(double amount) {
        if (amount <= 0) {
            std::cout << "Top-up rejected: Amount must be greater than 0\n";
            return;
        }
        this->balance += amount;
        std::cout << "Balance after top-up: " << this->balance << "\n";
    }

    void deduct(double amount) {
        if (amount > this.balance) {
            std::cout << "Deduct rejected: insufficient balance\n";
            return;
        }
        this->balance -= amount;
        std::cout << "Balance after deduction: " << this->balance << "\n";
    }

    double getBalance() const {
        return this->balance;
    }
};

int main() {
    MessWallet wallet(500);
    wallet.topUp(200);
    wallet.deduct(1000);
    std::cout << "Final balance: " << wallet.getBalance() << "\n";

    return 0;
}