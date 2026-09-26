#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Function to check for a leap year
bool isLeapYear(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

// Function to get the number of days in a given month
int getDaysInMonth(int y, int m) {
    if (m == 2) {
        return isLeapYear(y) ? 29 : 28;
    }
    int days[] = {0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return days[m];
}

// Function to add a specific number of days to a date
void addDays(int &y, int &m, int &d, int daysToAdd) {
    for (int i = 0; i < daysToAdd; i++) {
        d++;
        if (d > getDaysInMonth(y, m)) {
            d = 1;
            m++;
            if (m > 12) {
                m = 1;
                y++;
            }
        }
    }
}

int main() {
    int n;
    if (!(cin >> n)) return 0;

    for (int i = 0; i < n; i++) {
        string planType, name, startDateStr;
        cin >> planType >> name >> startDateStr;

        // Parse YYYY-MM-DD format manually
        int y = stoi(startDateStr.substr(0, 4));
        int m = stoi(startDateStr.substr(5, 2));
        int d = stoi(startDateStr.substr(8, 2));

        int validDays = 0;
        if (planType == "BASIC") {
            validDays = 30;
        } else if (planType == "STANDARD") {
            validDays = 90;
        } else if (planType == "PREMIUM") {
            validDays = 365;
        }

        // Add validity days to start date
        addDays(y, m, d, validDays);

        // Print formatted output with leading zeros if needed
        cout << name << ": " 
             << y << "-" 
             << setfill('0') << setw(2) << m << "-" 
             << setfill('0') << setw(2) << d << endl;
    }

    return 0;
}