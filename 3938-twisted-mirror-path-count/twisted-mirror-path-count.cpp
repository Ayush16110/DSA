class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long MOD = 1e9 + 7;

        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        dp[0][0] = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dp[i][j] == 0) continue;

                if (j + 1 < n) {
                    int ni = i, nj = j + 1;
                    int dir = 0; 
                    
                    bool valid = true;
                    while (ni < m && nj < n && grid[ni][nj] == 1) {
                        if (dir == 0) { 
                            ni++;
                            dir = 1; 
                        } else { 
                            nj++;
                            dir = 0;
                        }
                    }

                    if (ni < m && nj < n) {
                        dp[ni][nj] = (dp[ni][nj] + dp[i][j]) % MOD;
                    }
                }

                if (i + 1 < m) {
                    int ni = i + 1, nj = j;
                    int dir = 1; 
                    
                    bool valid = true;
                    while (ni < m && nj < n && grid[ni][nj] == 1) {
                        if (dir == 0) {
                            ni++;
                            dir = 1;
                        } else {
                            nj++;
                            dir = 0;
                        }
                    }

                    if (ni < m && nj < n) {
                        dp[ni][nj] = (dp[ni][nj] + dp[i][j]) % MOD;
                    }
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};