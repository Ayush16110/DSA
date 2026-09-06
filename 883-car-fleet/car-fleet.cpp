class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;

        for (int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.begin(), cars.end(),[](auto a, auto b) {
            return a.first > b.first; 
        });

        int count = 0;
        stack<double> st;

        for (auto& car : cars) {
            double time = (double)(target - car.first) / car.second;
            if (!st.empty() && time <= st.top()) {
                continue;
            }
            st.push(time);
            count++;
        }

        return count;
    }
};