class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;

        stack<pair<int, int>> st;

        int minLeft = nums[0];

        for (int i = 1; i < n; i++) {
            int prevMin = minLeft;

            while (!st.empty() && nums[i] >= st.top().first) {
                st.pop();
            }

            if (!st.empty() &&
                nums[i] > st.top().second) {
                return true;
            }

            st.push({nums[i], prevMin});

            minLeft = min(minLeft, nums[i]);
        }

        return false;
    }
};