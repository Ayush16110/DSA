class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;

        for(int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.begin(), cars.end(), [](auto a, auto b){
            return a.first > b.first;
        });

        stack<double> s;
        int count = 0;

        for(int i = 0; i < cars.size(); i++) {
            double time = (double)(target - cars[i].first) / cars[i].second;

            if(!s.empty() and s.top() >= time) {
                continue;
            }
            count++;
            s.push(time);
        }

        return count;
    }
};