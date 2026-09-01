class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> nums(1000, 0);

        for(auto t : trips) {
            int l = t[1], r = t[2], x = t[0];

            nums[l] += x;
            if(r < 1000) nums[r] -= x;
        }

        for(int i = 1; i < 1000; i++) {
            nums[i] += nums[i-1];
        }

        return capacity >= *max_element(nums.begin(), nums.end());
    }
};
