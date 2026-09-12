#include <iostream>
#include <string>

class Course {
private:
    std::string code;
    std::string title;
    int credits;
    int labCredits;

public:
    // Primary 4-argument constructor
    Course(std::string code, std::string title, int credits, int labCredits)
        : code(code), title(title), credits(credits), labCredits(labCredits) {}

    // Constructor delegating/chaining for theory-only courses (C++11 feature)
    Course(std::string code, std::string title, int credits)
        : Course(code, title, credits, 0) {}

    int totalCredits() const {
        return credits + labCredits;
    }

    std::string getCode() const {
        return code;
    }
};

int main() {
    Course theoryCourse("21CSC201J", "Data Structures", 4);
    Course labCourse("21CSC205L", "DSA Lab", 3, 1);

    std::cout << theoryCourse.getCode() << " total credits: " << theoryCourse.totalCredits() << "\n";
    std::cout << labCourse.getCode() << " total credits: " << labCourse.totalCredits() << "\n";

    return 0;
}