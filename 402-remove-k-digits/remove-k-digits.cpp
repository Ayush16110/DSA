class Solution {
public:
    string removeKdigits(string num, int k) {
        string s;
        for(char c : num) {
            while(!s.empty() and s.back() > c and k > 0) {
                k--;
                s.pop_back();
            }
            s.push_back(c);
        }
        while(k > 0) {
            s.pop_back();
            k--;
        }
        int i = 0;
        while(i < s.size() and s[i] == '0') {
            i++;
        }
        string ans = s.substr(i);
        return ans.empty() ? "0" : ans;
    }
};