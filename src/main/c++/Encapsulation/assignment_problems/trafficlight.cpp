#include <iostream>
#include <string>

class TrafficLight {
private:
    const std::string id;
    std::string color;

public:
    TrafficLight(const std::string& light_id) : id(light_id), color("RED") {}

    void next() {
        if (color == "RED") {
            color = "GREEN";
        } else if (color == "GREEN") {
            color = "YELLOW";
        } else if (color == "YELLOW") {
            color = "RED";
        }
    }

    std::string getColor() const {
        return color;
    }

    std::string getId() const {
        return id;
    }
};

// Usage Example
void testTrafficLight() {
    TrafficLight t("TL-9");
    std::cout << "Color: " << t.getColor() << "\n"; // RED
    t.next();
    std::cout << "Color: " << t.getColor() << "\n"; // GREEN
    t.next();
    std::cout << "Color: " << t.getColor() << "\n"; // YELLOW
    t.next();
    std::cout << "Color: " << t.getColor() << "\n"; // RED
}