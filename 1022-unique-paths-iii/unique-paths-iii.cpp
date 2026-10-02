class Solution {
private:
    vector<int> dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};
    int solve(vector<vector<int>>& grid, int i, int j, int remaining) {
        if (grid[i][j] == 2) {
            if (remaining == 0)
                return 1;
            return 0;
        }

        int ans = 0;
        grid[i][j] = -1;
        for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] == 1 || grid[x][y] == -1)
                continue;
            if (grid[x][y] == 2) {
                ans += solve(grid, x, y, remaining);
                
            } else {
                remaining--;
                ans += solve(grid, x, y, remaining);
                remaining++;
            }
        }
        grid[i][j] = 0;

        return ans;
    }

public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int sx = 0, sy = 0, remaining = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0)
                    remaining++;
                if (grid[i][j] == 1) {
                    sx = i;
                    sy = j;
                }
            }
        }
        return solve(grid, sx, sy, remaining);
    }
};