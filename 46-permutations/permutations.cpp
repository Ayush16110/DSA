class Solution {
private:
    vector<vector<int>> ans;
    void backtrack(vector<int>& nums, int i) {
        if(i == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for(int j = i; j < nums.size(); j++) {
            swap(nums[i], nums[j]);
            backtrack(nums, i+1);
            swap(nums[i], nums[j]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums, 0);
        return ans;
    }
};