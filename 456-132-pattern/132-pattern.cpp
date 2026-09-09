class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        // vector<int> minLeft(n);
        // minLeft[0] = nums[0];
        // for(int i = 1; i < n; i++) {
        //     minLeft[i] = min(minLeft[i-1], nums[i]);
        // }

        // for(int i = 1; i < n; i++) {
        //     if(minLeft[i-1] >= nums[i]) continue;
        //     for(int j = i + 1; j < n; j++) {
        //         if(nums[j] >= nums[i]) continue;
        //         if(nums[j] > minLeft[i-1]) return true;
        //     }
        // }

        // return false;

        int n = nums.size();
        if(n < 3) return false;
        stack<pair<int, int>> st;
        st.push({nums[0], nums[0]});
        int minLeft = nums[0];

        for(int i = 1; i < n; i++) {
            minLeft = min(minLeft, nums[i]);
            while(!st.empty() && nums[i] >= st.top().first) {
                st.pop();
            }
            if(!st.empty() && nums[i] < st.top().first && nums[i] > st.top().second) {
                return true;
            }
            else {
                st.push({nums[i], minLeft});
            }

        }
        return false;
    }
};