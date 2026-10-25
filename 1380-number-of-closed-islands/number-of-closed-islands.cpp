class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        vector<int> dx = {0, 1, 0, -1};
        vector<int> dy = {1, 0, -1, 0};
        int ans = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    queue<pair<int, int>> q;
                    bool isIsland = true;
                    q.push({i, j});
                    grid[i][j] = 1;
                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
                        if (x == 0 || y == 0 || x == grid.size() - 1 ||
                            y == grid[0].size() - 1) {
                            isIsland = false;
                        }

                        for (int k = 0; k < 4; k++) {
                            int nx = dx[k] + x;
                            int ny = dy[k] + y;

                            if (nx < 0 || ny < 0 || nx >= grid.size() ||
                                ny >= grid[0].size())
                                continue;

                            if (grid[nx][ny] == 0) {
                                q.push({nx, ny});
                                grid[nx][ny] = 1;
                            }
                        }
                    }

                    if (isIsland)
                        ans++;
                }
            }
        }

        return ans;
    }
};