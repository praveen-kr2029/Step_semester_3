#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;

    double grandTotal = 0.0;

    for (int i = 0; i < n; i++) {
        string type, name;
        double salary;
        cin >> type >> name >> salary;

        double bonus = 0.0;

        if (type == "FULLTIME") {
            bonus = salary * 0.10;
        } else if (type == "PARTTIME") {
            bonus = salary * 0.05;
        } else if (type == "INTERN") {
            bonus = 2000.0;
        }

        grandTotal += bonus;

        cout << name << ": " << fixed << setprecision(2) << bonus << endl;
    }

    cout << "Total Bonus: " << fixed << setprecision(2) << grandTotal << endl;

    return 0;
}