class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> freq(k, 0);
        int sum = 0;
        int ans = 0;
        freq[0] = 1;

        for(int n : nums) {
            sum += n;
            int rem = ((sum % k) + k) % k;

            ans += freq[rem];

            freq[rem]++;
        }

        return ans;
    }
};