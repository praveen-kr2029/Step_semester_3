#include <iostream>
#include <string>

class HallTicket {
public:
    std::string studentName;
    int seatNumber;

    HallTicket(std::string name, int seat) : studentName(name), seatNumber(seat) {}
};

int main() {
    // Dynamically allocating to emulate reference behavior (Java-like object references)
    HallTicket* priya = new HallTicket("Priya", 0);
    
    // Copy reference (both pointers now point to the exact same memory address)
    HallTicket* copy = priya;
    copy->seatNumber = 45;

    // Create a separate object
    HallTicket* separate = new HallTicket("Priya", 45);

    std::cout << "Priya's seatNumber (via first variable): " << priya->seatNumber << std::endl;
    std::cout << "copy == priya: " << (copy == priya ? "true" : "false") << std::endl;
    std::cout << "separate == priya: " << (separate == priya ? "true" : "false") << std::endl;

    // Clean up allocated memory
    delete priya;
    delete separate;

    return 0;
}