#include <iostream>
#include <string>

class IdCard {
public:
    std::string name;
    int booksIssued;

    IdCard(std::string name, int booksIssued)
        : name(name), booksIssued(booksIssued) {}
};

int main() {
    // Dynamically allocate to model reference-style variables like in Java/managed languages
    IdCard* ravi = new IdCard("Ravi", 0);
    IdCard* duplicate = ravi; // Points to the exact same heap memory location

    duplicate->booksIssued = 3;

    std::cout << "Ravi's booksIssued (via first variable): " << ravi->booksIssued << "\n";
    std::cout << std::boolalpha; // Print booleans as true/false instead of 1/0
    std::cout << "duplicate == ravi: " << (duplicate == ravi) << "\n";

    IdCard* separate = new IdCard("Ravi", 3); // A separate heap object memory space
    std::cout << "separate == ravi: " << (separate == ravi) << "\n";

    // Memory cleanup
    delete ravi;
    delete separate;

    return 0;
}