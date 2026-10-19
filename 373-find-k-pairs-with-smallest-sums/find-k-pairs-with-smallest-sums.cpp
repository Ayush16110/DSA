class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                       int k) {
        vector<vector<int>> ans;

        if (nums1.empty() || nums2.empty() || k <= 0)
            return ans;

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>> pq;

        int n = nums1.size();
        int m = nums2.size();

        for (int i = 0; i < min(k, n); i++) {
            pq.push({nums1[i] + nums2[0], i, 0});
        }

        while (k-- > 0 && !pq.empty()) {
            auto [sum, i, j] = pq.top();
            pq.pop();

            ans.push_back({nums1[i], nums2[j]});

            if (j + 1 < m) {
                pq.push({nums1[i] + nums2[j + 1], i, j + 1});
            }
        }

        return ans;
    }
};