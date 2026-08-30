class Solution {
public:
    int trap(vector<int>& height) {
        int leftMax = 0, rightMax = 0;
        int left = 0, right = height.size() - 1;

        int waterTrapped = 0;

        while(left < right) {
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);

            if(leftMax <= rightMax) {
                waterTrapped += leftMax - height[left++];
            } else {
                waterTrapped += rightMax - height[right--];
            }
        }

        return waterTrapped;
    }
};