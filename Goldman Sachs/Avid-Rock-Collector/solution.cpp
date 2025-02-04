#include <vector>
#include <iostream>

using namespace std;

int optimalPath(vector<vector<int>> &way) {
    int row_size = way.size();
    int col_size = way[0].size();
    vector<vector<int>> dp(row_size, vector<int>(col_size, 0));

    // Initialization
    dp[row_size - 1][0] = way[row_size - 1][0];
    for (int row = row_size-1; row >= 0; row--) {
        for (int col = 0; col < col_size; col++) {
            cout << row << " " << col << endl;
            // Ignore the start
            if (row == row_size - 1 && col == 0) {
                continue;
            }
            // Lowest row
            else if (row == row_size - 1) {
                dp[row][col] = dp[row][col - 1] + way[row][col];
            }
            // Left-most col
            else if (col == 0) {
                dp[row][col] = dp[row+1][col] + way[row][col];
            }
            // Others
            else {
                dp[row][col] = max(dp[row][col-1], dp[row+1][col]) + way[row][col];
            }
        }
    }

    return dp[0][col_size - 1];
}

int main() {
    vector<vector<int>> way = {{4, 0, 0, 0, 5}, {0, 1, 1, 1, 0}, {2, 0, 0, 0, 0}};
    cout << optimalPath(way);
    return 0;
}