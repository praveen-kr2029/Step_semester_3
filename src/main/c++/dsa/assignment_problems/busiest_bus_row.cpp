#include <iostream>
#include <vector>
#include <utility>

using namespace std;

// Function to find the busiest row in the grid
pair<int, int> busiestRow(const vector<vector<int>>& grid) {
    int best_row = 0;
    int max_total = -1;
    
    for (int i = 0; i < grid.size(); ++i) {
        int current_total = 0;
        for (int j = 0; j < grid[i].size(); ++j) {
            current_total += grid[i][j];
        }
        
        // Update only when strictly larger to handle ties 
        // by keeping the one with the smaller index
        if (current_total > max_total) {
            max_total = current_total;
            best_row = i;
        }
    }
    
    return {best_row, max_total};
}

int main() {
    vector<vector<int>> grid = {
        {2, 0, 1},
        {3, 3, 1},
        {1, 1, 1}
    };
    
    pair<int, int> result = busiestRow(grid);
    cout << "Expected Output: Row " << result.first << ", Total " << result.second << "\n";
    
    return 0;
}