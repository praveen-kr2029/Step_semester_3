#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <iomanip>

using namespace std;

class Delivery {
public:
    virtual ~Delivery() {}
    virtual double calculateFee() const = 0;
    virtual string getType() const = 0;
};

class StandardDelivery : public Delivery {
    double weight, distance;
public:
    StandardDelivery(double w, double d) : weight(w), distance(d) {}
    double calculateFee() const override {
        return 5.0 + (0.50 * weight) + (0.10 * distance);
    }
    string getType() const override {
        return "STANDARD";
    }
};

class ExpressDelivery : public Delivery {
    double weight, distance;
public:
    ExpressDelivery(double w, double d) : weight(w), distance(d) {}
    double calculateFee() const override {
        return 15.0 + (1.00 * weight) + (0.20 * distance);
    }
    string getType() const override {
        return "EXPRESS";
    }
};

class InternationalDelivery : public Delivery {
    double weight, distance, customsFee;
public:
    InternationalDelivery(double w, double d, double c) : weight(w), distance(d), customsFee(c) {}
    double calculateFee() const override {
        return 25.0 + (2.00 * weight) + (0.50 * distance) + customsFee;
    }
    string getType() const override {
        return "INTERNATIONAL";
    }
};

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<unique_ptr<Delivery>> deliveries;
    for (int i = 0; i < n; ++i) {
        string type;
        cin >> type;
        if (type == "STANDARD") {
            double w, d;
            cin >> w >> d;
            deliveries.push_back(make_unique<StandardDelivery>(w, d));
        } else if (type == "EXPRESS") {
            double w, d;
            cin >> w >> d;
            deliveries.push_back(make_unique<ExpressDelivery>(w, d));
        } else if (type == "INTERNATIONAL") {
            double w, d, c;
            cin >> w >> d >> c;
            deliveries.push_back(make_unique<InternationalDelivery>(w, d, c));
        }
    }

    double totalFee = 0.0;
    cout << fixed << setprecision(2);
    for (const auto& deliv : deliveries) {
        double fee = deliv->calculateFee();
        totalFee += fee;
        cout << deliv->getType() << ": " << fee << "\n";
    }
    cout << "Total: " << totalFee << "\n";

    return 0;
}