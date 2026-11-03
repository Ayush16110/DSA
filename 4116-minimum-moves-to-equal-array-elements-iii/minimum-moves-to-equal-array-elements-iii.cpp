class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans = 0;
        int mx = *max_element(nums.begin(), nums.end());
        for(int n : nums) {
            ans += mx - n;
        }
        return ans;
    }
};