#include <iostream>
#include <string>

class Employee {
private:
    std::string empId;
    std::string empName;
    double salary;
    bool isIntern;

public:
    // Primary Constructor for permanent employees
    Employee(std::string id, std::string name, double sal) 
        : empId(id), empName(name), salary(sal), isIntern(false) {}

    // Delegating Constructor (C++11) for interns chaining to the 3-argument constructor
    Employee(std::string id, std::string name) 
        : Employee(id, name, 0.0) {
        isIntern = true;
    }

    void printProfile() const {
        std::cout << empId << " | " << empName << " | Rs " << salary 
                  << " | Intern: " << (isIntern ? "true" : "false") << std::endl;
    }
};

int main() {
    Employee emp1("E-101", "Divya", 65000.0);
    Employee emp2("E-102", "Arjun");

    emp1.printProfile();
    emp2.printProfile();

    return 0;
}