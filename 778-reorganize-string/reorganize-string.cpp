class Solution {
public:
    string reorganizeString(string s) {
        string ans = "";
        unordered_map<char, int> freq;
        int half = s.length() % 2 == 0 ? s.length() / 2 : (s.length() / 2) + 1;
        for (char c : s) {
            freq[c]++;
        }
        priority_queue<pair<int, char>> pq;
        for (auto f : freq) {
            pq.push({f.second, f.first});
        }
        if (pq.top().first > half)
            return ans;

        for (int i = 0; i < s.size(); i++) {
            ans += '*';
        }

        int cnt = 0;
        char ch;
        for (int i = 0; i < s.size(); i = i + 2) {
            if (cnt == 0) {
                if (!pq.empty()) {
                    cnt = pq.top().first;
                    ch = pq.top().second;
                    pq.pop();
                }
            }
            ans[i] = ch;
            cnt--;
        }

        for (int i = 1; i < s.size(); i = i + 2) {
            if (cnt == 0) {
                if (!pq.empty()) {
                    cnt = pq.top().first;
                    ch = pq.top().second;
                    pq.pop();
                }
            }
            ans[i] = ch;
            cnt--;
        }

        return ans;
    }
};