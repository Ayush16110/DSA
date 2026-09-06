class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> temp(1001);

        for(auto t : trips) {
            int l = t[1];
            int r = t[2];
            int x = t[0];

            temp[l] += x;
            temp[r] -= x;
        }
        
        int sum = 0;
        for(int t : temp) {
            sum += t;
            if(sum > capacity) return false;
        }

        return true;
    }
};