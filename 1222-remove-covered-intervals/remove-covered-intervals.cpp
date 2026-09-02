class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int count = 0;
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] == b[0])
                     return a[1] > b[1];
                 return a[0] < b[0];
             });
        int prev = 0;

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[prev][1] > intervals[i][0] &&
                intervals[prev][1] >= intervals[i][1]) {
                count++;
            } else {
                prev = i;
            }
        }

        return intervals.size() - count;
    }
};