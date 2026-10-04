class Solution {
private:
    bool solve(string s, int i, int balance, vector<vector<int>>& dp) {
        if(balance < 0) return false;
        if(i == s.length()) {
            if(balance == 0) return true;
            return false;
        }
        
        if(dp[i][balance] != -1) return dp[i][balance]; 

        if(s[i] == '(') {
            if(solve(s, i + 1, balance + 1, dp)) return dp[i][balance] = true;
        } else if(s[i] == ')') {
            if(solve(s, i + 1, balance - 1, dp)) return dp[i][balance] = true;
        } else {
            if(solve(s, i + 1, balance + 1, dp)) return dp[i][balance] = true;
            if(solve(s, i + 1, balance - 1, dp)) return dp[i][balance] = true;
            if(solve(s, i + 1, balance, dp)) return dp[i][balance] = true;
        }

        return dp[i][balance] = false;
    }
public:
    bool checkValidString(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(s, 0, 0, dp);
    }
};