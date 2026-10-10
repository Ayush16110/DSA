class Solution {
private:
    bool isPossible(const vector<long long>& diff, long long k,
                    const long long mid) {
        for (auto d : diff) {
            if (d > mid) {
                k = k - (d - mid);
            }
        }
        return k >= 0;
    }

public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1,
                               int k2) {
        long long s = 0;
        vector<long long> diff;
        for (int i = 0; i < nums1.size(); i++) {
            diff.push_back(abs((long long)nums1[i] - nums2[i]));
        }
        long long total = accumulate(diff.begin(), diff.end(), 0LL);

        long long k = (long long)k1 + k2;
        
        if (total <= k)
            return 0;
            
        long long e = *max_element(diff.begin(), diff.end());

        while (s < e) {
            long long mid = s + (e - s) / 2;
            if (isPossible(diff, k, mid)) {
                e = mid;
            } else {
                s = mid + 1;
            }
        }

        long long remaining = k;

        for (auto d : diff) {
            if (d > s)
                remaining -= (d - s);
        }

        for (auto& d : diff) {
            d = min(d, s);
        }

        for (auto& d : diff) {
            if (remaining == 0)
                break;

            if (d == s) {
                d--;
                remaining--;
            }
        }

        long long ans = 0;
        for (auto d : diff) {
            ans += d * d;
        }

        return ans;
    }
};