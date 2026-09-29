class Solution {
private:
    vector<vector<string>> ans;
    bool isPalindrome(const string& s, int i, int j) {
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void helper(const string& s, int i, vector<string>& track) {
        if(i == s.length()) {
            ans.push_back(track);
            return;
        }

        for(int j = i; j < s.length(); j++) {
            if(isPalindrome(s, i, j)) {
                track.push_back(s.substr(i, j - i +1));
                helper(s, j + 1, track);
                track.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> track;
        helper(s, 0, track);
        return ans;
    }
};