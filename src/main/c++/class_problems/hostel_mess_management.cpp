#include <iostream>
#include <string>
#include <vector>

class PlacementRecord {
private:
    std::string studentName;
    std::string company;
    double packageLpa;

public:
    // Constructor using initializer list
    PlacementRecord(std::string studentName, std::string company, double packageLpa)
        : studentName(studentName), company(company), packageLpa(packageLpa) {}

    void printRecord() const {
        std::cout << studentName << " -> " << company << " @ " << packageLpa << " LPA\n";
    }
};

int main() {
    std::vector<PlacementRecord> records = {
        PlacementRecord("Ravi", "TCS", 4.5),
        PlacementRecord("Anitha", "Zoho", 6.2),
        PlacementRecord("Karthik", "Infosys", 4.0)
    };

    for (const auto& record : records) {
        record.printRecord();
    }

    return 0;
}