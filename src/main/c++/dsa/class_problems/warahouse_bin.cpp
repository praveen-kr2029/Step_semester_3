#include <iostream>
#include <vector>

using namespace std;

struct WarehouseSummaryResult {
    long long totalItems;
    pair<int, int> maxCoordinate;
};

WarehouseSummaryResult warehouseSummary(const vector<vector<int>>& grid) {
    long long total = 0;
    int maxVal = -1;
    pair<int, int> maxCoord = {-1, -1};

    int m = grid.size();
    if (m == 0) return {0, {-1, -1}};
    int n = grid[0].size();

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            total += grid[i][j];
            if (grid[i][j] > maxVal) {
                maxVal = grid[i][j];
                maxCoord = {i, j};
            }
        }
    }
    return {total, maxCoord};
}