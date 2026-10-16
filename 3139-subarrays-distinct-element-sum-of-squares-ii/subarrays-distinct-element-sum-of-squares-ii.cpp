class Solution {
    using ll = long long;
    static constexpr ll MOD = 1'000'000'007;

    struct Node {
        ll sum = 0;
        ll sq = 0;
        ll lazy = 0;
    };

    vector<Node> tree;
    int n;

    void apply(int node, int l, int r, ll val) {
        ll len = r - l + 1LL;
        ll oldSum = tree[node].sum;

        tree[node].sq =
            (tree[node].sq + 2LL * val % MOD * oldSum % MOD
             + val * val % MOD * len % MOD) % MOD;

        tree[node].sum =
            (oldSum + val * len) % MOD;

        tree[node].lazy =
            (tree[node].lazy + val) % MOD;
    }

    void push(int node, int l, int r) {
        if (tree[node].lazy == 0 || l == r)
            return;

        int mid = l + (r - l) / 2;
        ll val = tree[node].lazy;

        apply(node * 2, l, mid, val);
        apply(node * 2 + 1, mid + 1, r, val);

        tree[node].lazy = 0;
    }

    void pull(int node) {
        tree[node].sum =
            (tree[node * 2].sum + tree[node * 2 + 1].sum) % MOD;

        tree[node].sq =
            (tree[node * 2].sq + tree[node * 2 + 1].sq) % MOD;
    }

    void update(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr) {
            apply(node, l, r, 1);
            return;
        }

        push(node, l, r);
        int mid = l + (r - l) / 2;

        if (ql <= mid)
            update(node * 2, l, mid, ql, qr);

        if (qr > mid)
            update(node * 2 + 1, mid + 1, r, ql, qr);

        pull(node);
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        tree.assign(4 * n + 5, Node{});

        unordered_map<int, int> last;
        ll ans = 0;

        for (int j = 0; j < n; ++j) {
            int left = 0;

            auto it = last.find(nums[j]);
            if (it != last.end())
                left = it->second + 1;

            update(1, 0, n - 1, left, j);

            ans = (ans + tree[1].sq) % MOD;

            last[nums[j]] = j;
        }

        return static_cast<int>(ans);
    }
};