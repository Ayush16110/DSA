class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> minQ, maxQ;
        int ans = 0;
        int j = 0;

        for(int i = 0; i < nums.size(); i++) {
            while(!maxQ.empty() && nums[maxQ.back()] <= nums[i]) {
                maxQ.pop_back();
            }
            maxQ.push_back(i);
            while(!minQ.empty() && nums[minQ.back()] >= nums[i]) {
                minQ.pop_back();
            }
            minQ.push_back(i);

            while(!maxQ.empty() && !minQ.empty() && nums[maxQ.front()] - nums[minQ.front()] > limit) {
                j++;
                if(maxQ.front() < j) maxQ.pop_front();
                if(minQ.front() < j) minQ.pop_front();
            }

            ans = max(ans, i - j + 1);
        }

        return ans;
    }
};