class Solution {
private:
    vector<vector<int>> ans;
    void solve(int i, int n, int k, vector<int>& track) {
        if(track.size() == k) {
            ans.push_back(track);
            return;
        }

        for(int j = i; j <= n; j++) {
            track.push_back(j);
            solve(j+1, n, k, track);
            track.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> track;
        solve(1, n, k, track);
        return ans;
    }
};