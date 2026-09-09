class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> s;

        for(int i = 0; i < asteroids.size(); i++) {
            bool isDestroyed = false;
            int current = asteroids[i];
            while(!s.empty() && s.back() > 0 && current < 0) {
                if(abs(current) > s.back()) {
                    s.pop_back();
                } else if(abs(current) < s.back()) {
                    isDestroyed = true;
                    break;
                } else {
                    s.pop_back();
                    isDestroyed = true;
                    break;
                }
            }

            if(!isDestroyed) {
                s.push_back(current);
            }
        }

        return s;
    }
};