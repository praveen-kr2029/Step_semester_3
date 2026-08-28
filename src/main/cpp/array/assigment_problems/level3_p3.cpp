#include <iostream>

void simulateTrafficSignal(int cycles) {
    int stateIndex = 0; // 0 = Red, 1 = Green, 2 = Yellow

    for (int i = 0; i < cycles; ++i) {
        switch (stateIndex) {
            case 0:
                std::cout << "Red - Stop ";
                break;
            case 1:
                std::cout << "Green - Go ";
                break;
            case 2:
                std::cout << "Yellow - Prepare to stop ";
                break;
        }
        // Advance to next state and wrap back using modulo 3
        stateIndex = (stateIndex + 1) % 3;
    }
    std::cout << "\n";
}

int main() {
    std::cout << "Input: cycles = 3\nOutput: ";
    simulateTrafficSignal(3);

    return 0;
}