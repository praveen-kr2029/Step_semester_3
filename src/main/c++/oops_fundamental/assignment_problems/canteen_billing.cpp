#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    double grandTotal = 0.0;

    for (int i = 0; i < n; i++) {
        string type;
        double amount;
        cin >> type >> amount;

        double finalAmount = 0.0;

        if (type == "STUDENT") {
            finalAmount = amount * 0.90; // 10% discount
        } else if (type == "STAFF") {
            finalAmount = amount * 0.95; // 5% discount
        } else if (type == "GUEST") {
            finalAmount = amount + 10.0; // ₹10 service charge
        }

        grandTotal += finalAmount;

        // Display individual bill formatted to 2 decimal places
        cout << type << ": " << fixed << setprecision(2) << finalAmount << endl;
    }

    // Display total grand amount collected
    cout << "Total: " << fixed << setprecision(2) << grandTotal << endl;

    return 0;
}