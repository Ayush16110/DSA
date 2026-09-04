class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalFuel = accumulate(gas.begin(), gas.end(), 0);
        totalFuel -= accumulate(cost.begin(), cost.end(), 0);
        if(totalFuel < 0) return -1;

        int start = 0;
        int currentGas = 0;

        for(int i = 0; i < gas.size(); i++) {
            currentGas += gas[i] - cost[i];
            if(currentGas < 0) {
                currentGas = 0;
                start = i + 1;
                continue;
            }
        }

        return start;
    }
};