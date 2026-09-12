#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    double attendance;

public:
    // Static fields declarations
    static std::string collegeName;
    static int studentCount;

    Student(std::string name, double attendance)
        : name(name), attendance(attendance) {
        studentCount++; // Increment count when a new instance is created
    }

    // Static function accesses only static class variables
    static void printCollegeInfo() {
        std::cout << collegeName << "\n";
        std::cout << "Students created: " << studentCount << "\n";
    }
};

// Definition and initialization of static variables outside class scope
std::string Student::collegeName = "SRM Institute of Science and Technology";
int Student::studentCount = 0;

int main() {
    Student s1("Ravi", 85.5);
    Student s2("Anitha", 92.0);

    // Call static method through class scope, not through an instance reference
    Student::printCollegeInfo();

    return 0;
}