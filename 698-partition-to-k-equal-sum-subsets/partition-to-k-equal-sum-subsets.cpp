class Solution {
private:
    bool solve(vector<int>& nums, vector<int>& parts, int i, int target) {
        if(i == nums.size()) return true;
        unordered_set<int> s;
        for(int j = 0; j < parts.size(); j++) {
            if(parts[j] + nums[i] > target || s.contains(parts[j])) continue;
            parts[j] += nums[i];
            if(solve(nums, parts, i + 1, target)) return true;
            parts[j] -= nums[i];
            s.insert(parts[j]);
        }
        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        sort(nums.rbegin(), nums.rend());
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % k != 0) return false;
        vector<int> parts(k);
        int target = sum / k;
        return solve(nums, parts, 0, target);
    }
};