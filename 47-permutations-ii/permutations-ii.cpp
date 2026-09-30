class Solution {
private:
    vector<vector<int>> ans;
    void backtrack(vector<int>& nums, int i) {
        if (i == nums.size()) {
            ans.push_back(nums);
            return;
        }

        unordered_set<int> used;

        for (int j = i; j < nums.size(); j++) {
            if (used.contains(nums[j]))
                continue;
            used.insert(nums[j]);

            swap(nums[i], nums[j]);
            backtrack(nums, i + 1);
            swap(nums[i], nums[j]);
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        backtrack(nums, 0);
        return ans;
    }
};