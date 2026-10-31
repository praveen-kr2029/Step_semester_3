#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProfit(const vector<int>& prices) {
    if (prices.empty()) return 0;

    int minPrice = prices[0];
    int maxPft = 0;

    for (size_t i = 1; i < prices.size(); ++i) {
        minPrice = min(minPrice, prices[i]);
        int currentProfit = prices[i] - minPrice;
        maxPft = max(maxPft, currentProfit);
    }

    return maxPft;
}