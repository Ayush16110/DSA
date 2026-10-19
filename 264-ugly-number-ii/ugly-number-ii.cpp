class Solution {
public:
    int nthUglyNumber(int n) {
        unordered_set<int> alreadyInserted;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        pq.push(1);
        for(int i = 1; i < n; i++) {
            long long curr = pq.top();
            pq.pop();
            if(!alreadyInserted.contains(curr * 2)) {
                pq.push(curr * 2);
                alreadyInserted.insert(curr * 2);
            }
            if(!alreadyInserted.contains(curr * 3)) {
                pq.push(curr * 3);
                alreadyInserted.insert(curr * 3);
            }
            if(!alreadyInserted.contains(curr * 5)) {
                pq.push(curr * 5);
                alreadyInserted.insert(curr * 5);
            }
        }

        return (int)pq.top();
    }
};