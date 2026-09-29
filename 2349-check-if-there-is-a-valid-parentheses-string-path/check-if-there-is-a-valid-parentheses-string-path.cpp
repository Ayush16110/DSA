class Solution {
private:
    vector<int> dx = {0, 1}, dy = {1, 0};
    bool solve(vector<vector<char>>& grid, int i, int j, int balance, vector<vector<vector<int>>>& dp) {
        if(balance < 0) return false;
        if(i == grid.size()-1 and j == grid[0].size()-1) {
            return balance == 0;
        }
        if(dp[i][j][balance] != -1) return dp[i][j][balance];
        bool ans = false;
        for(int k = 0; k < 2; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if(x >= 0 and x < grid.size() and y >= 0 and y < grid[0].size()) {
                if(grid[x][y] == '(') {
                    if(solve(grid, x, y, balance + 1, dp)) ans = true;
                } else if(grid[x][y] == ')' and balance > 0) {
                    if(solve(grid, x, y, balance - 1, dp)) ans = true;
                }
            }
        }

        return dp[i][j][balance] = ans;
    }
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0] == ')' || grid[n-1][m-1] == '(') return false;
        if ((n + m - 1) % 2 == 1) return false;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(n + m, -1)));
        return solve(grid, 0, 0, 1, dp);
    }
};