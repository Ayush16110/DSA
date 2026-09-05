class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums1.size(), -1);
        stack<int> s;
        unordered_map<int, int> nextGreater;

        for(int i = 0; i < nums2.size(); i++) {
            int current = nums2[i];
            while(!s.empty() && current > nums2[s.top()]) {
                nextGreater[nums2[s.top()]] = current;
                s.pop();
            }
            s.push(i);
        }

        for(int i = 0; i < nums1.size(); i++) {
            if(nextGreater.find(nums1[i]) != nextGreater.end()) {
                ans[i] = nextGreater[nums1[i]];
            }
        }      

        return ans;
    }
};