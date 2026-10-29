
struct FenwickTree {
    int n;
    vector<int> tree;
    FenwickTree(int n) : n(n), tree(n + 1, 0) {}

    void add(int i, int delta) {
        for (; i <= n; i += i & -i) {
            tree[i] ^= delta;
        }
    }

    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= i & -i) {
            sum ^= tree[i];
        }
        return sum;
    }
};

class Solution {
    int n, LOGN;
    vector<vector<int>> adj;
    vector<int> mask;
    vector<vector<int>> up;
    vector<int> tin, tout;
    int timer;

    void dfs(int u, int p) {
        tin[u] = ++timer;
        up[u][0] = p;
        for (int i = 1; i < LOGN; ++i) {
            up[u][i] = up[up[u][i - 1]][i - 1];
        }
        for (int v : adj[u]) {
            if (v != p) {
                dfs(v, u);
            }
        }
        tout[u] = timer;
    }

    bool is_ancestor(int u, int v) {
        return tin[u] <= tin[v] && tout[u] >= tout[v];
    }

    int get_lca(int u, int v) {
        if (is_ancestor(u, v)) return u;
        if (is_ancestor(v, u)) return v;
        for (int i = LOGN - 1; i >= 0; --i) {
            if (!is_ancestor(up[u][i], v)) {
                u = up[u][i];
            }
        }
        return up[u][0]; 
    }

public:
    vector<bool> palindromePath(int n_nodes, vector<vector<int>>& edges, string s, vector<string>& queries) {
        n = n_nodes;
        LOGN = 1;
        while ((1 << LOGN) <= n) LOGN++;

        adj.assign(n + 1, vector<int>());
        mask.resize(n + 1);
        tin.resize(n + 1);
        tout.resize(n + 1);
        up.assign(n + 1, vector<int>(LOGN, 0));
        timer = 0;

        for (const auto& edge : edges) {
            int u = edge[0] + 1;
            int v = edge[1] + 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 1; i <= n; ++i) {
            mask[i] = 1 << (s[i - 1] - 'a');
        }

        dfs(1, 1);

        FenwickTree bit(timer);
        for (int i = 1; i <= n; ++i) {
            bit.add(tin[i], mask[i]);
            bit.add(tout[i] + 1, mask[i]);
        }

        vector<bool> result;

        for (const string& q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;

            if (type == "update") {
                int u_idx;
                char c;
                ss >> u_idx >> c;
                int u = u_idx + 1;

                int new_mask = 1 << (c - 'a');
                int delta = mask[u] ^ new_mask;
                mask[u] = new_mask;

                bit.add(tin[u], delta);
                bit.add(tout[u] + 1, delta);

            } else if (type == "query") {
                int u_idx, v_idx;
                ss >> u_idx >> v_idx;
                int u = u_idx + 1;
                int v = v_idx + 1;

                int lca = get_lca(u, v);
                int path_mask = bit.query(tin[u]) ^ bit.query(tin[v]) ^ mask[lca];

                if ((path_mask & (path_mask - 1)) == 0) {
                    result.push_back(true);
                } else {
                    result.push_back(false);
                }
            }
        }

        return result;
    }
};
