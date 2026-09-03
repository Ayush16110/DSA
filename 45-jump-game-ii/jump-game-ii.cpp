class Solution {
private:
    int helper(const vector<int>& nums, int idx, vector<int>& dp) {
        if (idx >= nums.size() - 1)
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        int ans = INT_MAX;

        for (int i = 1; i <= nums[idx] && idx + i < nums.size(); i++) {
            int jumps = helper(nums, idx + i, dp);

            if (jumps != INT_MAX) {
                ans = min(ans, jumps + 1);
            }
        }

        return dp[idx] = ans;
    }

public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return helper(nums, 0, dp);
    }
};
