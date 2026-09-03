class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end());

        int maxEnd = 0;
        int currentEnd = 0;
        int count = 0;
        int i = 0;

        while(currentEnd < time) {
            int oldEnd = currentEnd;

            while(i < clips.size() && clips[i][0] <= currentEnd) {
                maxEnd = max(maxEnd, clips[i][1]);
                i++;
            }

            if(maxEnd == oldEnd) return -1;

            count++;
            currentEnd = maxEnd;
        }

        return count;
    }
};