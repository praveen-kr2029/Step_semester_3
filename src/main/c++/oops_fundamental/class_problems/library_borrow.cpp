#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <iomanip>

using namespace std;

// Date structure for 2023 calendar date arithmetic
struct Date {
    int year, month, day;

    void addDays(int days) {
        day += days;
        int daysInMonths[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        while (day > daysInMonths[month]) {
            day -= daysInMonths[month];
            month++;
            if (month > 12) {
                month = 1;
                year++;
            }
        }
    }

    string toString() const {
        char buf[20];
        sprintf(buf, "%04d-%02d-%02d", year, month, day);
        return string(buf);
    }
};

class LibraryItem {
protected:
    string title;
public:
    LibraryItem(const string& t) : title(t) {}
    virtual ~LibraryItem() {}
    virtual int getBorrowingDays() const = 0;
    string getTitle() const { return title; }
    
    string getDueDate() const {
        Date d = {2023, 10, 26}; // Baseline current date
        d.addDays(getBorrowingDays());
        return d.toString();
    }
};

class Book : public LibraryItem {
public:
    Book(const string& t) : LibraryItem(t) {}
    int getBorrowingDays() const override { return 14; }
};

class DVD : public LibraryItem {
public:
    DVD(const string& t) : LibraryItem(t) {}
    int getBorrowingDays() const override { return 7; }
};

class Magazine : public LibraryItem {
public:
    Magazine(const string& t) : LibraryItem(t) {}
    int getBorrowingDays() const override { return 3; }
};

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<unique_ptr<LibraryItem>> items;
    for (int i = 0; i < n; ++i) {
        string type, title;
        cin >> type;
        
        char ch;
        do {
            cin.get(ch);
        } while (ch != '"' && !cin.eof());

        getline(cin, title, '"'); // Read until the closing quote

        if (type == "BOOK") {
            items.push_back(make_unique<Book>(title));
        } else if (type == "DVD") {
            items.push_back(make_unique<DVD>(title));
        } else if (type == "MAGAZINE") {
            items.push_back(make_unique<Magazine>(title));
        }
    }

    for (const auto& item : items) {
        cout << item->getTitle() << ": " << item->getDueDate() << "\n";
    }

    return 0;
}