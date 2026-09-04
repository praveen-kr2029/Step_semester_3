#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>

struct RoundResult {
    int roundNumber;
    std::string playerMove;
    std::string computerMove;
    std::string result; // "Player Wins", "Computer Wins", or "Draw"
};

std::string playRound(const std::string& playerMove, const std::string& computerMove) {
    if (playerMove == computerMove) {
        return "Draw";
    }
    if ((playerMove == "Rock" && computerMove == "Scissors") ||
        (playerMove == "Paper" && computerMove == "Rock") ||
        (playerMove == "Scissors" && computerMove == "Paper")) {
        return "Player Wins";
    }
    return "Computer Wins";
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::vector<std::string> moves = {"Rock", "Paper", "Scissors"};
    std::vector<std::string> playerChoices = {"Rock", "Paper", "Scissors", "Rock", "Paper"}; // Predefined demo inputs
    int numRounds = 5;

    std::vector<RoundResult> history;
    int wins = 0, losses = 0, draws = 0;

    for (int i = 0; i < numRounds; ++i) {
        std::string playerMove = playerChoices[i % playerChoices.size()];
        std::string computerMove = moves[std::rand() % 3];

        std::string result = playRound(playerMove, computerMove);

        if (result == "Player Wins") wins++;
        else if (result == "Computer Wins") losses++;
        else draws++;

        history.push_back({i + 1, playerMove, computerMove, result});
    }

    // Display Summary Table
    std::cout << std::left 
              << std::setw(8)  << "Round" 
              << std::setw(14) << "| Player Move" 
              << std::setw(16) << "| Computer Move" 
              << "| Result\n";
    std::cout << "---------------------------------------------------\n";

    for (const auto& round : history) {
        std::cout << std::left 
                  << std::setw(8)  << round.roundNumber 
                  << "| " << std::setw(12) << round.playerMove 
                  << "| " << std::setw(14) << round.computerMove 
                  << "| " << round.result << "\n";
    }

    double winPercentage = (static_cast<double>(wins) / numRounds) * 100.0;

    std::cout << "\nFinal Summary (after " << numRounds << " rounds)\n";
    std::cout << "Wins: " << wins 
              << " | Losses: " << losses 
              << " | Draws: " << draws 
              << " | Win % = " << std::fixed << std::setprecision(1) << winPercentage << "%\n";

    return 0;
}