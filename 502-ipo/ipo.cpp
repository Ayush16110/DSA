class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minCapitals;
        priority_queue<int> maxProfits;
        for(int i = 0 ; i < profits.size(); i++) {
            minCapitals.push({capital[i], profits[i]});
        }

        for(int i = 0; i < k; i++) {
            while(!minCapitals.empty() and minCapitals.top().first <= w) {
                maxProfits.push(minCapitals.top().second);
                minCapitals.pop();
            }

            if(maxProfits.empty()) break;
            w += maxProfits.top();
            maxProfits.pop(); 
        }

        return w;
    }
};