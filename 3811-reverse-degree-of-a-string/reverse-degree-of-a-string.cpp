class Solution {
public:
    int reverseDegree(string s) {
        vector<int> degree(26);
        int deg = 26;
        for(int &d: degree) {
            d = deg;
            deg--;
        }
        int ans = 0;
        for(int i = 0; i < s.size(); i++) {
            int prod = i + 1;
            prod *= degree[s[i] - 'a'];
            ans += prod;
        }

        return ans;
    }
};