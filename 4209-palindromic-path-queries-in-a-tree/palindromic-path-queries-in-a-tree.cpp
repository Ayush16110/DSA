
class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> parent(n, -1), depth(n), sz(n);
        vector<int> heavy(n, -1), head(n), pos(n);
        int timer = 0;
        function<void(int,int)> dfs = [&](int u, int p) {
            parent[u] = p;
            sz[u] = 1;
            int largest = 0;
            for (int v : adj[u]) {
                if (v == p) continue;
                depth[v] = depth[u] + 1;
                dfs(v, u);
                sz[u] += sz[v];
                if (sz[v] > largest) {
                    largest = sz[v];
                    heavy[u] = v;
                }
            }
        };
        function<void(int,int)> decompose = [&](int u, int h) {
            head[u] = h;
            pos[u] = timer++;
            if (heavy[u] != -1)
                decompose(heavy[u], h);
            for (int v : adj[u]) {
                if (v == parent[u] || v == heavy[u]) continue;
                decompose(v, v);
            }
        };
        dfs(0, -1);
        decompose(0, 0);
        vector<int> seg(4 * n, 0);
        function<void(int,int,int)> build = [&](int node, int l, int r) {
            if (l == r) {
                seg[node] = 1 << (s[0] - 'a');
                return;
            }
            int mid = (l + r) / 2;
            build(node * 2, l, mid);
            build(node * 2 + 1, mid + 1, r);
            seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
        };
        vector<int> base(n);
        for (int u = 0; u < n; u++)
            base[pos[u]] = 1 << (s[u] - 'a');
        function<void(int,int,int)> buildTree = [&](int node, int l, int r) {
            if (l == r) {
                seg[node] = base[l];
                return;
            }
            int mid = (l + r) / 2;
            buildTree(node * 2, l, mid);
            buildTree(node * 2 + 1, mid + 1, r);
            seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
        };
        buildTree(1, 0, n - 1);
        function<void(int,int,int,int,int)> update =
            [&](int node, int l, int r, int idx, int mask) {
                if (l == r) {
                    seg[node] = mask;
                    return;
                }
                int mid = (l + r) / 2;
                if (idx <= mid)
                    update(node * 2, l, mid, idx, mask);
                else
                    update(node * 2 + 1, mid + 1, r, idx, mask);

                seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
            };
        function<int(int,int,int,int,int)> rangeQuery =
            [&](int node, int l, int r, int ql, int qr) -> int {
                if (qr < l || r < ql) return 0;
                if (ql <= l && r <= qr) return seg[node];
                int mid = (l + r) / 2;
                return rangeQuery(node * 2, l, mid, ql, qr)
                     ^ rangeQuery(node * 2 + 1, mid + 1, r, ql, qr);
            };
        auto queryPath = [&](int u, int v) {
            int mask = 0;
            while (head[u] != head[v]) {
                if (depth[head[u]] < depth[head[v]])
                    swap(u, v);
                mask ^= rangeQuery(1, 0, n - 1, pos[head[u]], pos[u]);
                u = parent[head[u]];
            }
            if (depth[u] > depth[v]) swap(u, v);
            mask ^= rangeQuery(1, 0, n - 1, pos[u], pos[v]);
            return mask;
        };
        vector<bool> ans;
        for (string &q : queries) {
            string type;
            int u;
            stringstream ss(q);
            ss >> type >> u;
            if (type == "update") {
                char c;
                ss >> c;
                s[u] = c;
                update(1, 0, n - 1, pos[u], 1 << (c - 'a'));
            } else {
                int v;
                ss >> v;
                int mask = queryPath(u, v);
                ans.push_back((mask & (mask - 1)) == 0);
            }
        }
        return ans;
    }
};