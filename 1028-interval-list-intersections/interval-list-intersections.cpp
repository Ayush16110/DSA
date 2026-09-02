class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                             vector<vector<int>>& secondList) {
        int i = 0, j = 0;
        vector<vector<int>> ans;

        while (i < firstList.size() && j < secondList.size()) {
            if (firstList[i][0] <= secondList[j][1] &&
                secondList[j][0] <= firstList[i][1]) {
                // overlapping then only find intersection
                int start = max(firstList[i][0], secondList[j][0]);
                int end = min(firstList[i][1], secondList[j][1]);

                if (start <= end) {
                    ans.push_back({start, end});
                }
            }
            // increment whose end is smaller
            if (firstList[i][1] <= secondList[j][1]) {
                i++;
            } else
                j++;
        }

        return ans;
    }
};