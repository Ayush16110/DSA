class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int sum = 0;
        freq[0] = 1;
        int ans = 0;

        for(int n : nums) {
            sum += n;
            ans += freq[sum - k];
            freq[sum]++;
        }

        return ans;
    }
};