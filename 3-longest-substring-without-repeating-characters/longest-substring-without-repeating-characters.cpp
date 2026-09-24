class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> latestOccurrence;
        int left = 0;
        int ans = 0;
        for (int right = 0; right < s.length(); right++) {
            char ch = s[right];
            if (latestOccurrence.find(ch) != latestOccurrence.end() and
                latestOccurrence[ch] >= left) {
                left = latestOccurrence[ch] + 1;
            }
            latestOccurrence[ch] = right;
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};