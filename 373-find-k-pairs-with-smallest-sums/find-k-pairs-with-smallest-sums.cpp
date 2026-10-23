class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        int n = nums1.size();
        int m = nums2.size();

        for(int i = 0; i < min(n, k); i++) {
            minHeap.push({nums1[i] + nums2[0], i, 0});
        }

        vector<vector<int>> ans;
        while(!minHeap.empty() && ans.size() < k) {
            int sum = minHeap.top()[0], i = minHeap.top()[1], j = minHeap.top()[2];
            minHeap.pop();
            if(j + 1 < m) minHeap.push({nums1[i] + nums2[j+1], i, j+1});
            ans.push_back({nums1[i], nums2[j]});
        }

        return ans;
    }
};