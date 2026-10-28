class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;
        int n = grid.size();
        queue<pair<int, int>> q;
        int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
        int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        q.push({0, 0});
        int ans = 1;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto [i, j] = q.front();
                if(i == n - 1 && j == n - 1) return ans;
                q.pop();

                for(int k = 0; k < 8; k++) {
                    int u = i + dx[k];
                    int v = j + dy[k];

                    if(u < 0 || v < 0 || u >= n || v >= n || grid[u][v] == 1) continue;
                    grid[u][v] = 1;
                    q.push({u, v});
                }
            }
            ans++;
        }

        return -1;
    }
};