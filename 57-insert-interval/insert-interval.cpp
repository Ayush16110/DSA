class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if (intervals.size() == 0)
            return {newInterval};

        auto it =
            lower_bound(intervals.begin(), intervals.end(), newInterval[0],
                        [](const vector<int>& interval, int value) {
                            return interval[0] < value;
                        });

        intervals.insert(it, newInterval);
        vector<vector<int>> mergeInterval;
        mergeInterval.push_back(intervals[0]);
        for(auto curr : intervals) {
            if(mergeInterval.back()[1] >= curr[0]) {
                mergeInterval.back()[1] = max(mergeInterval.back()[1], curr[1]);
            } else {
                mergeInterval.push_back(curr);
            }
        }

        return mergeInterval;
    }
};