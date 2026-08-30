class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for (int n : nums) {
            s.insert(n);
        }
        int ans = 0;

        for (auto n : s) {
            if (!s.contains(n - 1)) {
                int len = 1;
                while (s.contains(n + 1)) {
                    n++;
                    len++;
                }
                ans = max(ans, len);
            }
        }

        return ans;
    }
};