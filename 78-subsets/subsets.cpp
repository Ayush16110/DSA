class Solution {
private: 
vector<vector<int>> ans;
void solve(vector<int>& nums, int i, vector<int>& track) {
    if(i == nums.size()) {
        ans.push_back(track);
        return;
    }

    solve(nums, i+1, track);
    track.push_back(nums[i]);
    solve(nums, i+1, track);
    track.pop_back();
}
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> track;
        solve(nums, 0, track);
        return ans;
    }
};