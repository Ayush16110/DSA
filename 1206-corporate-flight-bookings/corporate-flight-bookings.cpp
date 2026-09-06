class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans (n, 0);

        for(auto &b : bookings) {
            int l = b[0], r = b[1], x = b[2];

            ans[l-1] += x;
            if(r < n) ans[r] -= x;
        }

        for(int i = 1; i < n; i++) {
            ans[i] += ans[i-1];
        }

        return ans;
    }
};