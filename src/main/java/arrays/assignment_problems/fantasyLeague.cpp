#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Player {
public:
    std::string name;
    int matchesPlayed;
    double battingAverage;
    bool injured;

    Player(std::string name, int matchesPlayed, double battingAverage, bool injured)
        : name(name), matchesPlayed(matchesPlayed), battingAverage(battingAverage), injured(injured) {}

    // Overloaded < operator to simulate Comparable in C++ (descending order by batting average)
    bool operator<(const Player& other) const {
        return this->battingAverage > other.battingAverage;
    }
};

// Overloaded checks
bool isDraftable(int matchesPlayed) {
    return matchesPlayed >= 10; // Established player threshold
}

bool isDraftable(int matchesPlayed, bool injured) {
    return matchesPlayed >= 5 && !injured; // Emerging player threshold
}

std::string draftAndRank(const std::vector<Player>& players) {
    std::vector<Player> draftable;

    for (const auto& player : players) {
        // Check rule 1 (established player) OR rule 2 (emerging non-injured player)
        if (isDraftable(player.matchesPlayed) || isDraftable(player.matchesPlayed, player.injured)) {
            draftable.push_back(player);
        }
    }

    // Sort descending using standard library algorithm
    std::sort(draftable.begin(), draftable.end());

    std::string result = "";
    for (size_t i = 0; i < draftable.size(); ++i) {
        result += std::to_string(i + 1) + ". " + draftable[i].name;
        if (i < draftable.size() - 1) {
            result += " | ";
        }
    }
    return result;
}

int main() {
    std::vector<Player> players = {
        Player("Virat", 15, 48.0, false),
        Player("Rahul", 7, 55.0, false),
        Player("Sameer", 3, 60.0, false),
        Player("Dev", 12, 20.0, true)
    };

    std::cout << draftAndRank(players) << std::endl;
    return 0;
}