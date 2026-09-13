class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<pair<int, int>> dq;
        int ans = INT_MAX;
        int sum = 0;

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(sum >= k) ans = min(ans, i+1);

            while(!dq.empty() and sum - dq.front().first >= k) {
                ans = min(ans, i - dq.front().second);
                dq.pop_front();
            }

            while(!dq.empty() and sum <= dq.back().first) {
                dq.pop_back();
            }

            dq.push_back({sum, i});
        }

        return (ans == INT_MAX) ? -1 : ans;
    } 
};