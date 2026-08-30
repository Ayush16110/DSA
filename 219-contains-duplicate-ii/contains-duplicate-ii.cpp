class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> lastSeen;

        for(int i = 0; i < k && i < nums.size(); i++) {
            if(lastSeen.find(nums[i]) != lastSeen.end()) return true;
            lastSeen[nums[i]] = i;
        }

        for(int i = k; i < nums.size(); i++) {
            if(lastSeen.find(nums[i]) != lastSeen.end() && lastSeen[nums[i]] >= i-k) return true;
            lastSeen[nums[i]] = i;
        }

        return false;
    }
};
