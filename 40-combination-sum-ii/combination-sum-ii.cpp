class Solution {
    vector<vector<int>> ans;
    vector<int> track;
    void solve(vector<int>& nums, int target, int i) {
        if(target == 0) {
            ans.push_back(track);
            return;
        }

        if(i == nums.size()) return;
        for(int j = i; j < nums.size(); j++) {
            if(j > i && nums[j] == nums[j-1]) continue;
            if(target - nums[j] < 0) continue;
            track.push_back(nums[j]);
            solve(nums, target - nums[j], j + 1);
            track.pop_back();
        }

    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        solve(candidates, target, 0);
        return ans;
    }
};