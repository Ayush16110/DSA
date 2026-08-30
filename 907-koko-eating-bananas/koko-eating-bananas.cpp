class Solution {
private:
    bool isPossible(const vector<int>& piles, int h, int k) {
        long long hours = 0;

        for(int p : piles) {
            hours += (p + k - 1)/k;
            if(hours > h) return false;
        }

        return true;
    }


public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = *max_element(piles.begin(), piles.end());
        int mid;

        while(start < end) {
            mid = start + (end - start)/2;
            if(isPossible(piles, h, mid)) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }

        return start;
    }
};