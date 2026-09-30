class Solution {
private:
    bool backtrack(vector<int>& match, vector<int>& sides, int target, int i) {
        if(i == match.size()) return true;
        unordered_set<int> s;
        for(int j = 0; j < 4; j++) {
            if(sides[j] + match[i] > target || s.contains(sides[j])) continue;
            sides[j] += match[i];
            if(backtrack(match, sides, target, i+1)) return true;
            sides[j] -= match[i];
            s.insert(sides[j]);
        }
        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        int total = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if(total % 4 != 0) return false;
        int target = total / 4;
        vector<int> sides(4, 0);
        sort(matchsticks.rbegin(), matchsticks.rend());
        return backtrack(matchsticks, sides, target, 0);
    }
};