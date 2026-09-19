#include <iostream>
#include <vector>
#include <algorithm>

class Scorecard {
private:
    const int maxQuestions;
    std::vector<bool> results;

public:
    Scorecard(int max_q) : maxQuestions(max_q) {}

    void recordAnswer(bool isCorrect) {
        if (results.size() < maxQuestions) {
            results.push_back(isCorrect);
        }
    }

    int getScore() const {
        int score = 0;
        for (bool result : results) {
            if (result) {
                score++;
            }
        }
        return score;
    }
};

// Usage Example
void testScorecard() {
    Scorecard sc(4);
    sc.recordAnswer(true);
    sc.recordAnswer(true);
    sc.recordAnswer(false);
    sc.recordAnswer(true);
    
    std::cout << "Score: " << sc.getScore() << "\n"; // 3
}