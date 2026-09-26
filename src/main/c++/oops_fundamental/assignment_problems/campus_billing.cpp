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
        int hours;
        cin >> type >> hours;

        double charge = 0.0;

        if (type == "BIKE") {
            charge = hours * 10.0;
        } else if (type == "CAR") {
            if (hours == 1) {
                charge = 30.0;
            } else {
                charge = 30.0 + (hours - 1) * 20.0;
            }
        } else if (type == "TRUCK") {
            charge = hours * 50.0;
            if (charge < 100.0) {
                charge = 100.0; // Minimum charge
            }
        }

        grandTotal += charge;

        cout << type << ": " << fixed << setprecision(2) << charge << endl;
    }

    cout << "Total: " << fixed << setprecision(2) << grandTotal << endl;

    return 0;
}