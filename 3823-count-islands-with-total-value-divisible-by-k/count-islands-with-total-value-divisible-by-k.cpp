class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};
        int ans = 0;
        queue<pair<int, int>> q;

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] > 0) {
                    long long sum = grid[i][j];
                    grid[i][j] = 0;
                    q.push({i, j});

                    while(!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
                        for(int k = 0; k < 4; k++) {
                            int nx = x + dx[k];
                            int ny = y + dy[k];

                            if(nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size()) continue;
                            if(grid[nx][ny] > 0) {
                                sum += grid[nx][ny];
                                grid[nx][ny] = 0;
                                q.push({nx, ny});
                            }
                        }
                    }


                    if(sum % k == 0) ans++;
                }
            }
        }

        return ans;
    }
};