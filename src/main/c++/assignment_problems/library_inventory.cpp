#include <iostream>
#include <string>
#include <vector>

class BookInventory {
private:
    std::string title;
    std::string author;
    int copiesAvailable;

public:
    BookInventory(std::string t, std::string a, int copies) 
        : title(t), author(a), copiesAvailable(copies) {}

    void printEntry() const {
        std::cout << title << " by " << author << " - " << copiesAvailable << " copies available" << std::endl;
    }
};

int main() {
    // Array of 4 BookInventory objects
    BookInventory inventory[4] = {
        BookInventory("Clean Code", "Robert C. Martin", 3),
        BookInventory("Effective Java", "Joshua Bloch", 5),
        BookInventory("Refactoring", "Martin Fowler", 0),
        BookInventory("Design Patterns", "GoF", 2)
    };

    for (int i = 0; i < 4; ++i) {
        inventory[i].printEntry();
    }

    return 0;
}