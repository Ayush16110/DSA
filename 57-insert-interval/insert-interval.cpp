class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        if(intervals.size() == 0) return {newInterval};
        int i = 0;
        vector<vector<int>> ans;
        while(i < intervals.size() && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i]);
            i++;
        }

        vector<int> OverlappedInterval = newInterval;

        while(i < intervals.size() && intervals[i][0] <= newInterval[1] && newInterval[0] <= intervals[i][1]) {
            OverlappedInterval[0] = min(intervals[i][0], OverlappedInterval[0]);
            OverlappedInterval[1] = max(intervals[i][1], OverlappedInterval[1]);
            i++;
        }

        ans.push_back(OverlappedInterval);
        
        while(i < intervals.size() && i < intervals.size()) {
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};