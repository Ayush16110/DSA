class Solution {
private:
    vector<string> ans;
    vector<string> m = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void helper(const string &digits, int i, string track) {
        if(i == digits.size()) {
            ans.push_back(track);
            return;
        }

        int index = digits[i] - '0';
        for(int j = 0; j < m[index].length(); j++) {
            track.push_back(m[index][j]);
            helper(digits, i+1, track);
            track.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        helper(digits, 0, "");
        return ans;
    }
};