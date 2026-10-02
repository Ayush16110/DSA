class Solution {
private:
    int ans = 0;
    void solve(vector<int>& nums, int target, int i, int sum) {
        if(i == nums.size()) {
            if(sum == target) ans++;
            return;
        } 
        solve(nums, target, i+1, sum + nums[i]);
        solve(nums, target, i+1, sum - nums[i]);
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        solve(nums, target, 0, 0);
        return ans;
    }
};