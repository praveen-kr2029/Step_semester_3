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
        double units;
        cin >> type >> units;

        double billAmount = 0.0;

        if (type == "SINGLE") {
            billAmount = units * 8.0;
        } else if (type == "SHARED") {
            int occupants;
            cin >> occupants;
            billAmount = (units * 6.0) / occupants;
        } else if (type == "AC") {
            billAmount = (units * 10.0) + 200.0;
        }

        grandTotal += billAmount;

        cout << type << ": " << fixed << setprecision(2) << billAmount << endl;
    }

    cout << "Total: " << fixed << setprecision(2) << grandTotal << endl;

    return 0;
}