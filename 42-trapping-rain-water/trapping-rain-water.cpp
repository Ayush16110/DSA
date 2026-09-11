class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> s;
        int ans = 0;

        for(int i = 0; i < height.size(); i++) {
            while(!s.empty() and height[i] > height[s.top()]) {
                int bottom = s.top();
                s.pop();

                if(s.empty()) break;

                int leftBoundary = s.top();
                int width = i - leftBoundary - 1;
                int water = min(height[leftBoundary], height[i]) - height[bottom];
                ans += water * width; 
            }

            s.push(i);
        }

        return ans;
    }
};