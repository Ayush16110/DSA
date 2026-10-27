class Solution {
private:
    void dfs(vector<vector<int>>& matrix, vector<bool>& visited, int node) {
        for(int i = 0; i < matrix.size(); i++) {
            if(matrix[node][i] == 1 && visited[i] == false) {
                visited[i] = true;
                dfs(matrix, visited, i);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size(), false);
        int count = 0;
        for(int i = 0; i < isConnected.size(); i++) {
            if(visited[i] == false) {
                count++;
                visited[i] = true;
                dfs(isConnected, visited, i);
            }
        }

        return count;
    }
};