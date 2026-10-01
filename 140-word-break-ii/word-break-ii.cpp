class Solution {
private:
    vector<string> ans;
    void backtrack(string& s, unordered_set<string>& dic, int i, string track) {
        if(i == s.length()) {
            track.pop_back();
            // popping extra space
            ans.push_back(track);
            return;
        }
        for(int j = i; j < s.length(); j++) {
            if(dic.contains(s.substr(i, j-i+1))) {
                backtrack(s, dic, j + 1, track + s.substr(i, j - i + 1) + " ");
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dic(wordDict.begin(), wordDict.end());
        backtrack(s, dic, 0, "");
        return ans;
    }
};