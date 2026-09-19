#include <iostream>
#include <algorithm>

class Character {
private:
    const int maxHealth;
    int health;

public:
    Character(int max_hp) : maxHealth(max_hp), health(max_hp) {}

    void takeDamage(int amount) {
        if (amount > 0) {
            health = std::max(0, health - amount);
        }
    }

    void heal(int amount) {
        if (amount > 0) {
            health = std::min(maxHealth, health + amount);
        }
    }

    int getHealth() const {
        return health;
    }
};

// Usage Example
void testHealthBar() {
    Character c(100);
    c.takeDamage(30);
    std::cout << "Health: " << c.getHealth() << "\n"; // 70
    c.heal(50);
    std::cout << "Health: " << c.getHealth() << "\n"; // 100
    c.takeDamage(150);
    std::cout << "Health: " << c.getHealth() << "\n"; // 0
}