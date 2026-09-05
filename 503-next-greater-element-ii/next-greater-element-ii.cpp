class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        int n = nums.size();
        vector<int> ans(n, -1);

        for (int i = 0; i < 2 * n; i++) {
            int idx = i % n;

            while (!s.empty() && nums[idx] > nums[s.top()]) {
                ans[s.top()] = nums[idx];
                s.pop();
            }

            if (i < n) {
                s.push(idx);
            }
        }

        return ans;
    }
};