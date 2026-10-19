class Solution {
private:
    int firstOccurrence(vector<int>& nums, int target) {
        int ans = -1;
        int start = 0;
        int end = nums.size() - 1;
        int mid = 0;
        while(start <= end) {
            mid = start + (end - start)/2;
            if(nums[mid] == target) {
                ans = mid;
                end = mid - 1;
            } else if(nums[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }

public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int first = firstOccurrence(nums, target);
        vector<int> ans;
        if(first == -1) return ans;
        int i = first;
        while(i < nums.size() && nums[i] == nums[first]) {
            ans.push_back(i);
            i++;
        }
        return ans;
    }
};