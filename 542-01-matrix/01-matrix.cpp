class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int, int>> q;
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> ans(m, vector<int> (n, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0) {
                    q.push({i , j});
                } 
            }
        }

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};
        int level = 0;
        while(!q.empty()) {
            int sz = q.size();
            level++;
            while(sz--) {
                auto [i, j] = q.front();
                q.pop();

                for(int k = 0; k < 4; k++) {
                    int u = i + dx[k];
                    int v = j + dy[k];

                    if(u < 0 || v < 0 || u >= m || v >= n || mat[u][v] == 0) continue;
                    ans[u][v] = level;
                    mat[u][v] = 0;
                    q.push({u, v});
                }
            }
        }

        return ans;
    }
};