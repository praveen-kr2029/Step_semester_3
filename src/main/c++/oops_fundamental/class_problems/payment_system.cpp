#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <iomanip>

using namespace std;

// Base class for Payment Method using polymorphism
class PaymentMethod {
protected:
    double amount;
public:
    PaymentMethod(double amt) : amount(amt) {}
    virtual ~PaymentMethod() {}
    virtual double calculateAdjustedAmount() const = 0;
    virtual string getName() const = 0;
};

class CardPayment : public PaymentMethod {
public:
    CardPayment(double amt) : PaymentMethod(amt) {}
    double calculateAdjustedAmount() const override {
        return amount * 1.02; // 2% processing fee
    }
    string getName() const override {
        return "CARD";
    }
};

class WalletPayment : public PaymentMethod {
public:
    WalletPayment(double amt) : PaymentMethod(amt) {}
    double calculateAdjustedAmount() const override {
        return amount * 1.01; // 1% processing fee
    }
    string getName() const override {
        return "WALLET";
    }
};

class BankTransferPayment : public PaymentMethod {
public:
    BankTransferPayment(double amt) : PaymentMethod(amt) {}
    double calculateAdjustedAmount() const override {
        return amount; // No processing fee
    }
    string getName() const override {
        return "BANKTRANSFER";
    }
};

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<unique_ptr<PaymentMethod>> payments;
    for (int i = 0; i < n; ++i) {
        string type;
        double amount;
        cin >> type >> amount;
        if (type == "CARD") {
            payments.push_back(make_unique<CardPayment>(amount));
        } else if (type == "WALLET") {
            payments.push_back(make_unique<WalletPayment>(amount));
        } else if (type == "BANKTRANSFER") {
            payments.push_back(make_unique<BankTransferPayment>(amount));
        }
    }

    double total = 0.0;
    cout << fixed << setprecision(2);
    for (const auto& p : payments) {
        double adjusted = p->calculateAdjustedAmount();
        total += adjusted;
        cout << p->getName() << ": " << adjusted << "\n";
    }
    cout << "Total: " << total << "\n";

    return 0;
}