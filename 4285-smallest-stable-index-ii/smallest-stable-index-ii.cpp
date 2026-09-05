class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int ans = INT_MAX;
        vector<int> minArr(nums.size(), INT_MAX);
        minArr[nums.size() - 1] = nums[nums.size() -1];
        for(int i = nums.size() - 2; i >= 0; i--) {
            minArr[i] = min(minArr[i + 1], nums[i]);
        }

        int currMax = 0;
        for(int i = 0; i < nums.size(); i++) {
            currMax = max(currMax, nums[i]);
            if(currMax - minArr[i] <= k) ans = min(i, ans);
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};