class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int fresh = 0;
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) fresh++;
                else if(grid[i][j] == 2) q.push({i, j});
            }
        }

        vector<int> dx = {0, 1, 0, -1}, dy = {1, 0, -1, 0};
        int ans = 0;
        while(!q.empty() && fresh > 0) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                auto [x, y] = q.front();
                q.pop();

                for(int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if(nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] != 1) continue;
                    grid[nx][ny] = 2;
                    fresh--;
                    q.push({nx, ny});
                }
            }
            ans++;
        }

        return fresh > 0 ? -1 : ans;
    }
};