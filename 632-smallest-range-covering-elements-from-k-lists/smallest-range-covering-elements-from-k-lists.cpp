class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        vector<int> ans(2);
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>> pq;
        int mx = INT_MIN; 
        for(int i = 0; i < k; i++) {
            pq.push({nums[i][0], i, 0});
            mx = max(mx, nums[i][0]);
        }
        int minRangeLen = mx - get<0>(pq.top()) + 1;
        ans[0] = get<0>(pq.top());
        ans[1] = mx;

        while(true) {
            auto [n, i, j] = pq.top();
            if(j + 1 < nums[i].size()) {
                pq.pop();
                mx = max(mx, nums[i][j+1]);
                pq.push({nums[i][j+1], i, j+1});

                int rangeLen = mx - get<0>(pq.top()) + 1;
                if(rangeLen < minRangeLen) {
                    minRangeLen = rangeLen;
                    ans[0] = get<0>(pq.top());
                    ans[1] = mx;
                }
            } else break;
        }

        return ans;
    }
};