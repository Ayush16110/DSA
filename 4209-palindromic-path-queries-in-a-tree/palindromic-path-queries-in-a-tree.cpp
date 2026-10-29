class Solution {
    vector<vector<int>> adj, up;
    vector<int> depth, parent, tin, tout, sz, pref;
    int timer, LOG;
    struct SegTree {
        int n;
        vector<int> lazy;
        SegTree(int n) : n(n), lazy(4 * n, 0) {}
        void update(int node, int l, int r,
                    int ql, int qr, int val) {
            if (ql <= l && r <= qr) {
                lazy[node] ^= val;
                return;
            }
            int mid = (l + r) / 2;
            if (ql <= mid)
                update(node * 2, l, mid, ql, qr, val);
            if (qr > mid)
                update(node * 2 + 1, mid + 1, r,
                       ql, qr, val);
        }
        void update(int l, int r, int val) {
            if (l <= r)
                update(1, 1, n, l, r, val);
        }
        int query(int node, int l, int r, int pos) {
            if (l == r)
                return lazy[node];
            int mid = (l + r) / 2;
            if (pos <= mid)
                return lazy[node] ^
                       query(node * 2, l, mid, pos);
            return lazy[node] ^
                   query(node * 2 + 1, mid + 1, r, pos);
        }
        int query(int pos) {
            return query(1, 1, n, pos);
        }
    };
    int bit(char c) {
        return 1 << (c - 'a');
    }
    void preprocess(int n) {
        vector<int> order;
        order.reserve(n);
        vector<int> st = {0};
        parent[0] = 0;
        while (!st.empty()) {
            int u = st.back();
            st.pop_back();
            tin[u] = ++timer;
            order.push_back(u);
            for (int v : adj[u]) {
                if (v == parent[u]) continue;
                parent[v] = u;
                depth[v] = depth[u] + 1;
                st.push_back(v);
            }
        }
        for (int u : order)
            sz[u] = 1;
        for (int i = n - 1; i > 0; --i) {
            int u = order[i];
            sz[parent[u]] += sz[u];
        }
        for (int u = 0; u < n; ++u)
            tout[u] = tin[u] + sz[u] - 1;
        for (int u = 0; u < n; ++u)
            up[0][u] = parent[u];
        for (int k = 1; k < LOG; ++k) {
            for (int u = 0; u < n; ++u) {
                up[k][u] = up[k - 1][up[k - 1][u]];
            }
        }
    }
    int lca(int u, int v) {
        if (depth[u] < depth[v])
            swap(u, v);
        int diff = depth[u] - depth[v];
        for (int k = 0; k < LOG; ++k) {
            if (diff & (1 << k))
                u = up[k][u];
        }
        if (u == v)
            return u;
        for (int k = LOG - 1; k >= 0; --k) {
            if (up[k][u] != up[k][v]) {
                u = up[k][u];
                v = up[k][v];
            }
        }
        return parent[u];
    }
public:
    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        LOG = 1;
        while ((1 << LOG) <= n)
            ++LOG;
        adj.assign(n, {});
        up.assign(LOG, vector<int>(n));
        depth.assign(n, 0);
        parent.assign(n, 0);
        tin.assign(n, 0);
        tout.assign(n, 0);
        sz.assign(n, 0);
        pref.assign(n, 0);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        timer = 0;
        preprocess(n);
        vector<int> order(n);
        for (int u = 0; u < n; ++u)
            order[tin[u] - 1] = u;
        for (int u : order) {
            pref[u] = bit(s[u]);
            if (u != 0)
                pref[u] ^= pref[parent[u]];
        }
        string suneravilo = s;
        SegTree seg(n);
        vector<bool> ans;
        for (const string& q : queries) {
            stringstream ss(q);
            string op;
            int u;
            ss >> op >> u;
            if (op == "update") {
                char c;
                ss >> c;
                int delta = bit(s[u]) ^ bit(c);
                seg.update(tin[u], tout[u], delta);
                s[u] = c;
            } else {
                int v;
                ss >> v;
                int w = lca(u, v);
                int pu = pref[u] ^ seg.query(tin[u]);
                int pv = pref[v] ^ seg.query(tin[v]);
                int mask = pu ^ pv ^ bit(s[w]);
                ans.push_back((mask & (mask - 1)) == 0);
            }
        }
        return ans;
    }
};
