class Solution {
private:
    vector<vector<int>> ans;
    vector<int> current;
    void solve(int k, int n, int i) {
        if(current.size() == k && n == 0) {
            ans.push_back(current);
            return;
        }

        for(int j = i; j < 10; j++) {
            if(j > n) break;
            
            current.push_back(j);
            solve(k, n - j, j + 1);
            current.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        solve(k, n, 1);
        return ans;
    }
};