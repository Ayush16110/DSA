class Solution {
    int mod = 1000000007;
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> right(n, n-1), left(n, 0);
        stack<int> s;

        for(int i = 0; i < n; i++) {
            while(!s.empty() and arr[i] < arr[s.top()]) {
                right[s.top()] = i - 1;
                s.pop();
            }
            s.push(i);
        }

        while(!s.empty()) s.pop();

        for(int i = n-1; i >= 0; i--) {
            while(!s.empty() and arr[i] <= arr[s.top()]) {
                left[s.top()] = i + 1;
                s.pop();
            }
            s.push(i);
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            int s = i - left[i] + 1;
            int e = right[i] - i + 1;
            int score = (1LL * s * e * arr[i]) % mod;
            ans = (ans + score) % mod;
        }

        return ans;
    }
};