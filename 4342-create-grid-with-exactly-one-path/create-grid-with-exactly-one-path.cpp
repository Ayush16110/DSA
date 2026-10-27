class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        string temp = "";
        for(int i = 0; i < n; i++) {
            temp.push_back('.');
        }
        ans.push_back(temp);
        for(int i = 0; i < temp.size() - 1; i++) {
            temp[i] = '#';
        }
        for(int i = 1; i < m; i++) {
            ans.push_back(temp);
        }
        return ans;
    }
};