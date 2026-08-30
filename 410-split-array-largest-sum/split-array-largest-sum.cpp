class Solution {
private:
    bool isPossible(const vector<int>& nums, int k, int mid) {
        int subArrayCount = 1;
        int sum = 0;

        for(int n : nums) {
            if(sum + n <= mid) {
                sum += n;
            } else {
                sum = n;
                subArrayCount++;
            }

            if(subArrayCount > k) return false;
        }

        return true;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int start = *max_element(nums.begin(), nums.end());
        int end = accumulate(nums.begin(), nums.end(), 0);
        int mid;

        while(start < end) {
            mid = start + (end - start)/2;

            if(isPossible(nums, k, mid)) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }

        return start;
    }
};