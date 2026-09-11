class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int ans1 = INT_MIN;
        int sum = 0;

        // case 1: no wrapping and all negatives are also handled
        for(int n : nums) {
            sum += n;
            ans1 = max(ans1, sum);
            if(sum <= 0) {
                sum = 0;
            }
        }

        int ans2 = INT_MAX;
        sum = 0;

        // case 2: wrapping subarrays
        for(int n : nums) {
            sum += n;
            ans2 = min(ans2, sum);

            if(sum >= 0) sum = 0;
        }

        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if(totalSum != ans2) ans2 = totalSum - ans2;

        return max(ans1, ans2);
    }
};