class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n, 0);

        for(int i = 0; i < bookings.size(); i++) {
            int l = bookings[i][0];
            int r = bookings[i][1];
            int s = bookings[i][2];

            ans[l-1] += s;
            if(r < n) ans[r] -= s;
        }

        for(int i = 1; i < n; i++) {
            ans[i] += ans[i-1];
        }

        return ans;
    }
};