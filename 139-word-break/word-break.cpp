class Solution {
private:
    bool solve(string s, unordered_set<string>& dic, int i, vector<int>& dp) {
        if(i == s.length()) return true;
        if(dp[i] != -1) return dp[i];
        for(int j = i; j < s.length(); j++) {
            if(dic.contains(s.substr(i, j - i + 1))) {
                if(solve(s, dic, j + 1, dp)) return dp[i] = true;
            }
        }
        return dp[i] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dic(wordDict.begin(), wordDict.end());
        vector<int> dp(s.length() + 1, -1);
        return solve(s, dic, 0, dp);
    }
};