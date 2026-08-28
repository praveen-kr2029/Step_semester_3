#include <iostream>

void classifyWithAttendance(int marks, int attendance) {
    // Check if both minimum attendance and passing marks are met
    if (attendance >= 75 && marks >= 40) {
        if (marks >= 90) {
            std::cout << "Grade: A\n";
        } else if (marks >= 75) {
            std::cout << "Grade: B\n";
        } else if (marks >= 60) {
            std::cout << "Grade: C\n";
        } else {
            std::cout << "Grade: D\n";
        }
    } else {
        std::cout << "Detained\n";
    }
}

int main() {
    // Test Case 1
    std::cout << "Input: marks = 82, attendance = 80\nOutput: ";
    classifyWithAttendance(82, 80);

    // Test Case 2
    std::cout << "\nInput: marks = 91, attendance = 60\nOutput: ";
    classifyWithAttendance(91, 60);

    return 0;
}