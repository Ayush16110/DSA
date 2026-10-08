class Solution {
public:
    string removeOuterParentheses(const string& s) {
        int balance = 0;
        string ans = "";
        int lastBreak = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') balance++;
            if(s[i] == ')') balance--;
            if(balance == 0) {
                string temp = s.substr(lastBreak + 1, i - lastBreak - 1);
                lastBreak = i + 1;
                ans += temp;
            }
        }
        return ans;
    }
};