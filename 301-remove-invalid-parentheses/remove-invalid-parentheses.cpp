class Solution {
private:
    unordered_set<string> ans;
    int minRemoval = INT_MAX;
    bool isValid(const string& s) {
        int balance = 0;
        for (char c : s) {
            if (c == '(')
                balance++;
            if (c == ')') {
                balance--;
                if (balance < 0)
                    return false;
            }
        }
        return balance == 0;
    }

    void solve(const string& s, string& track, int i) {
        if (i == s.length()) {
            if (isValid(track)) {
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
        // pick non brackets
        if (s[i] != '(' and s[i] != ')') {
            track.push_back(s[i]);
            solve(s, track, i + 1);
            track.pop_back();
        } else {
            // pick
            track.push_back(s[i]);
            solve(s, track, i + 1);
            track.pop_back();
            // not pick
            solve(s, track, i + 1);
        }
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        string track = "";
        solve(s, track, 0);
        vector<string> finalAns(ans.begin(), ans.end());
        return finalAns;
    }
};