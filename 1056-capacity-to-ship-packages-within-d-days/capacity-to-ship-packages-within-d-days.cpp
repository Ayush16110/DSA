class Solution {
private:
    bool isPossible(const vector<int>& weights,const int days, int k) {
        int sum = 0;
        int day = 1;
        for(int w : weights) {
            if(sum + w > k) {
                day++;
                sum = w;
            } else {
                sum += w;
            }
        }
        return day <= days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int start = *max_element(weights.begin(), weights.end());
        int end = accumulate(weights.begin(), weights.end(), 0);
        int mid = start + (end - start)/2; 
        
        while(start < end) {
            mid = start + (end - start)/2; 
            if(isPossible(weights, days, mid)) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }

        return start;
    }
};