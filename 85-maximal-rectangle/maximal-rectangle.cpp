class Solution {
private:
    int helper(vector<int>& heights, int n) {
        vector<int> left(n, 0), right(n, n-1);
        stack<int> s;
        for(int i = 0; i < n; i++) {
            while(!s.empty() && heights[i] < heights[s.top()]) {
                right[s.top()] = i - 1;
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i = n-1; i >= 0; i--) {
            while(!s.empty() && heights[i] < heights[s.top()]) {
                left[s.top()] = i + 1;
                s.pop();
            }
            s.push(i);
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int width = right[i] - left[i] + 1;
            int area = width * heights[i];
            ans = max(ans, area);
        }
        return ans;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix[0].size();
        vector<int> heights(n, 0);
        int ans = 0;
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == '1') heights[j]++;
                else heights[j] = 0;
            }

            ans = max(ans, helper(heights, n));
        }

        return ans;
    }
};