class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int n : nums) {
            freq[n]++;
        }

        vector<vector<int>> bucket(nums.size() + 1);
        for(auto f : freq) {
            bucket[f.second].push_back(f.first);
        }

        vector<int> ans;
        for(int i = bucket.size() - 1; i >= 0; i--) {
            if(k == 0) break;
            if(bucket[i].size() == 0) continue;
            for(int n : bucket[i]) {
                if(k == 0) break;
                ans.push_back(n);
                k--;
            }
        }

        return ans;
    }
};