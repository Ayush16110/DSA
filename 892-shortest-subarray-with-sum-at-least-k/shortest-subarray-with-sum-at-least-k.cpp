class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<pair<int, int>> dq;
        int shortest = INT_MAX;
        long long sum = 0;

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if(sum >= k) shortest = min(shortest, i+1);

            while(!dq.empty() && (sum - dq.front().first) >= k) {
                shortest = min(shortest, i - dq.front().second);
                dq.pop_front();
            }

            while(!dq.empty() && sum <= dq.back().first) {
                dq.pop_back();
            }
            dq.push_back({sum, i});
        }

        return shortest == INT_MAX ? -1 : shortest;
    }
};