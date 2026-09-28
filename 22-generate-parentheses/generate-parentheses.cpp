class Solution {
private:
    vector<string> ans;
    void helper(int n, string track, int currentlyOpened) {
        if(n == 0) {
            for(int i = 0; i < currentlyOpened; i++) track = track + ')';
            ans.push_back(track);
            return;
        }

        // open bracket
        helper(n - 1, track + '(', currentlyOpened + 1);
        // resolve previous one if exists
        if(currentlyOpened > 0) helper(n, track + ')', currentlyOpened - 1);
    }
public:
    vector<string> generateParenthesis(int n) {
        helper(n, "", 0);
        return ans;
    }
};