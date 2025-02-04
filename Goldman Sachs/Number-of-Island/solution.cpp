#include <vector>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int row, int col, int row_count, int col_count) {
        // Mark the island to be water (visited)
        grid[row][col] = 0;
        // up, right, down, left
        vector<vector<int>> move = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for (int i = 0; i < 4; i++){
            int next_row = row + move[i][0];
            int next_col = col + move[i][1];
            if (next_row >= 0 && next_row < row_count &&
                next_col >= 0 && next_col < col_count &&
                grid[next_row][next_col] == '1') {
                    dfs(grid, next_row, next_col, row_count, col_count);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int row_count = grid.size();
        int col_count = grid[0].size();
        int island_count = 0;
        for (int row = 0; row < row_count; row++) {
            for (int col = 0; col < col_count; col++) {
                if (grid[row][col] == '1') {
                    dfs(grid, row, col, row_count, col_count);
                    island_count += 1;
                }
            }
        }
        return island_count;
    }
};