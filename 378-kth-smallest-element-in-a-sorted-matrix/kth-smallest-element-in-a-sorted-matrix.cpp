class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        
        int n = matrix.size();

        for(int i = 0; i < n; i++) {
            pq.push({matrix[i][0], {i, 0}});
        }

        int count = 0;

        while(count < k-1) {
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            if(j+1 < n) pq.push({matrix[i][j+1], {i, j + 1}});
            count++;
        }

        return pq.top().first;
    }
};