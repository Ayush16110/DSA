class Solution {
private:
    unordered_set<string> ans;
    int minRemoval = INT_MAX;

    void solve(const string& s, string& track, int i, int balance) {
        if (i == s.length()) {
            if (balance == 0) {
                int removal = s.length() - track.length();
                if (removal == minRemoval) {
                    ans.insert(track);
                } else if (removal < minRemoval) {
                    ans.clear();
                    ans.insert(track);
                    minRemoval = removal;
                }
            }
            return;
        }

        if (balance < 0)
            return;

        // pick non brackets
        if (s[i] != '(' and s[i] != ')') {
            track.push_back(s[i]);
            solve(s, track, i + 1, balance);
            track.pop_back();
        } else {
            // pick
            track.push_back(s[i]);
            if (s[i] == '(')
                solve(s, track, i + 1, balance + 1);
            else
                solve(s, track, i + 1, balance - 1);
            track.pop_back();
            // not pick
            solve(s, track, i + 1, balance);
        }
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        string track = "";
        solve(s, track, 0, 0);
        vector<string> finalAns(ans.begin(), ans.end());
        return finalAns;
    }
};