class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int sum = 0;
        freq[0] = 1;
        int ans = 0;

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            ans += freq[sum - k];

            freq[sum]++;
        }

        return ans;
    }
};