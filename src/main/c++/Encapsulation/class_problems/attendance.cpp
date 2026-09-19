#include <iostream>
#include <string>
#include <vector>

class AttendanceSheet {
private:
    const int maxCapacity;
    std::vector<std::string> presentStudents;

public:
    AttendanceSheet(int capacity) : maxCapacity(capacity) {}

    void markPresent(const std::string& name) {
        if (presentStudents.size() < maxCapacity && !isPresent(name)) {
            presentStudents.push_back(name);
        }
    }

    bool isPresent(const std::string& name) const {
        for (const std::string& student : presentStudents) {
            if (student == name) {
                return true;
            }
        }
        return false;
    }

    int getPresentCount() const {
        return presentStudents.size();
    }
};

// Usage Example
void testAttendanceSheet() {
    AttendanceSheet sheet(30);
    sheet.markPresent("Ana");
    sheet.markPresent("Ben");
    sheet.markPresent("Ana"); // Ignored, already present
    
    std::cout << "Count: " << sheet.getPresentCount() << "\n"; // 2
    std::cout << "Is Ben present? " << (sheet.isPresent("Ben") ? "Yes" : "No") << "\n"; // Yes
    std::cout << "Is Chen present? " << (sheet.isPresent("Chen") ? "Yes" : "No") << "\n"; // No
}