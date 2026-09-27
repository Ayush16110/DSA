class Solution {
private:
    vector<vector<int>> ans;
    void solve(vector<int>& nums, int i, vector<int>& track, int target) {
        if(target == 0) {
            ans.push_back(track);
            return;
        }
        if(i == nums.size() || target < 0) return;
        solve(nums, i+1, track, target);
        track.push_back(nums[i]);
        solve(nums, i, track, target - nums[i]);
        track.pop_back();
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> track;
        solve(candidates, 0, track, target);
        return ans;
    }
};