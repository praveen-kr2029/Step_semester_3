#include <iostream>
#include <string>

class Employee {
private:
    std::string empName;
    double salary;

public:
    static std::string companyName;
    static int employeeCount;

    Employee(std::string name, double sal) : empName(name), salary(sal) {
        employeeCount++;
    }

    // Static method: can only access static members
    static void printCompanyInfo() {
        std::cout << companyName << std::endl;
        std::cout << "Employees: " << employeeCount << std::endl;
    }
};

// Static member variable definitions (required in C++)
std::string Employee::companyName = "Bright Horizon Technologies";
int Employee::employeeCount = 0;

int main() {
    Employee emp1("Aarav", 50000.0);
    Employee emp2("Bhavna", 60000.0);
    Employee emp3("Chetan", 55000.0);

    // Called through the class name, not an instance
    Employee::printCompanyInfo();

    return 0;
}