class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> radiant, dire;

        for (int i = 0; i < senate.size(); i++) {
            char s = senate[i];
            if (s == 'R')
                radiant.push(i);
            else
                dire.push(i);
        }

        while (!radiant.empty() && !dire.empty()) {
            int r = radiant.front();
            int d = dire.front();

            if (r < d) {
                radiant.pop();
                dire.pop();
                radiant.push(r + senate.size());
            } else {
                dire.pop();
                radiant.pop();
                dire.push(d + senate.size());
            }
        }

        if (radiant.empty())
            return "Dire";
        return "Radiant";
    }
};