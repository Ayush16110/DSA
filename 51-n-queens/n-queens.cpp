class Solution {
unordered_set<int> col, diag, antiDiag;
vector<vector<string>> ans;
private:
    void solve(int n, int r, vector<string>& track) {
        if(r >= n) {
            ans.push_back(track);
            return;
        }

        string temp = "";
        for(int i = 0; i < n; i++) temp += '.';
        for(int c = 0; c < n; c++) {
            if(!col.contains(c) && !diag.contains(r+c) && !antiDiag.contains(r-c)) {
                temp[c] = 'Q';
                track.push_back(temp);
                col.insert(c);
                diag.insert(r+c);
                antiDiag.insert(r-c);
                solve(n, r+1, track);
                antiDiag.erase(r-c);
                diag.erase(r+c);
                col.erase(c);
                track.pop_back();
                temp[c] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> track;
        solve(n, 0, track);
        return ans;
    }
};