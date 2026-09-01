class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedIntervals;
        sort(intervals.begin(), intervals.end());

        mergedIntervals.push_back(intervals[0]);
        int prev = 0;

        for(auto curr : intervals) {
            if(curr[0] <= mergedIntervals[prev][1]) {
                mergedIntervals[prev][1] = max(mergedIntervals[prev][1], curr[1]);
            } else {
                mergedIntervals.push_back(curr);
                prev++;
            }
        }

        return mergedIntervals;
    }
};