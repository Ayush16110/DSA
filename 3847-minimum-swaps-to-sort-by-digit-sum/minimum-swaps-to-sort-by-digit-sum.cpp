class Solution {
private:
    int digitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> sortedArray;

        for (int i = 0; i < n; i++) {
            sortedArray.push_back({nums[i], i});
        }

        sort(sortedArray.begin(), sortedArray.end(), [&](auto& a, auto& b) {
            int sa = digitSum(a.first);
            int sb = digitSum(b.first);

            if (sa != sb)
                return sa < sb;
            return a.first < b.first;
        });

        int swaps = 0;
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++) {
            if (visited[i] || sortedArray[i].second == i)
                continue;
            int j = i;
            int cycleLength = 0;

            while (!visited[j]) {
                visited[j] = true;
                j = sortedArray[j].second;
                cycleLength++;
            }

            swaps += cycleLength - 1;
        }

        return swaps;
    }
};