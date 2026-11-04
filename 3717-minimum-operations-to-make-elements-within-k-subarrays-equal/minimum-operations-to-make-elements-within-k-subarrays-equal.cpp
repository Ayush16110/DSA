class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        multiset<long long> lo, hi;
        long long sumLo = 0, sumHi = 0;
        auto add = [&](long long val) {
            if (lo.empty() || val <= *lo.rbegin()) {
                lo.insert(val);
                sumLo += val;
            } else {
                hi.insert(val);
                sumHi += val;
            }
            while (lo.size() > hi.size() + 1) {
                long long v = *lo.rbegin();
                lo.erase(prev(lo.end()));
                sumLo -= v;
                hi.insert(v);
                sumHi += v;
            }
            while (lo.size() < hi.size()) {
                long long v = *hi.begin();
                hi.erase(hi.begin());
                sumHi -= v;
                lo.insert(v);
                sumLo += v;
            }
        };
        auto remove = [&](long long val) {
            auto it = lo.find(val);
            if (it != lo.end()) {
                lo.erase(it);
                sumLo -= val;
            } else {
                it = hi.find(val);
                hi.erase(it);
                sumHi -= val;
            }
            while (lo.size() > hi.size() + 1) {
                long long v = *lo.rbegin();
                lo.erase(prev(lo.end()));
                sumLo -= v;
                hi.insert(v);
                sumHi += v;
            }
            while (lo.size() < hi.size()) {
                long long v = *hi.begin();
                hi.erase(hi.begin());
                sumHi -= v;
                lo.insert(v);
                sumLo += v;
            }
        };
        vector<long long> cost(n - x + 1);
        for (int i = 0; i < n; i++) {
            add(nums[i]);
            if (i >= x) {
                remove(nums[i - x]);
            }
            if (i >= x - 1) {
                long long median = *lo.rbegin();
                cost[i - x + 1] =
                    median * (long long)lo.size() - sumLo +
                    sumHi - median * (long long)hi.size();
            }
        }
        const long long INF = 4e18;
        vector<long long> prev(n + 1, 0), curr(n + 1, INF);
        for (int j = 1; j <= k; j++) {
            fill(curr.begin(), curr.end(), INF);
            for (int i = 1; i <= n; i++) {
                curr[i] = curr[i - 1];
                if (i >= x && prev[i - x] != INF) {
                    curr[i] = min(
                        curr[i],
                        prev[i - x] + cost[i - x]
                    );
                }
            }
            swap(prev, curr);
        }
        return prev[n];
    }
};
