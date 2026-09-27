class Solution {
private:
    vector<vector<int>> ans;
    void backtrack(vector<int>& nums, int i, vector<int>& track) {
        ans.push_back(track);
        for(int j = i; j < nums.size(); j++) {
            if(j > i && nums[j] == nums[j-1]) continue;

            track.push_back(nums[j]);
            backtrack(nums, j + 1, track);
            track.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> track;
        backtrack(nums, 0, track);
        return ans;
    }
};