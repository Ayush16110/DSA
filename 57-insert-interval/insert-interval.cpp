class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        if(intervals.size() == 0) return {newInterval};
        if (intervals.back()[1] < newInterval[0]) {
            intervals.push_back(newInterval);
            return intervals;
        }

        if (newInterval[1] < intervals[0][0]) {
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        }

        vector<vector<int>> mergeInterval;
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
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