class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for (auto word : words) {
            freq[word]++;
        }

        auto cmp = [](const pair<int, string>& a, const pair<int, string>& b) {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first > b.first;
        };
        
        priority_queue<pair<int, string>, vector<pair<int, string>>,
                       decltype(cmp)>
            pq(cmp);

        for (auto f : freq) {
            pq.push({f.second, f.first});
            while (pq.size() > k)
                pq.pop();
        }

        vector<string> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};