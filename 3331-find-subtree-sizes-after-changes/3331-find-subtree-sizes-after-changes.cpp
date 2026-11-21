
class Solution {
 public:
  vector<int> findSubtreeSizes(vector<int>& parent, string s) {
    int n = parent.size();

    vector<vector<int>> tree(n);

    for (int i = 1; i < n; i++) {
      tree[parent[i]].push_back(i);
    }

    vector<int> last(26, -1);
    vector<int> newParent(n, -1);

    function<void(int)> build = [&](int u) {
      int c = s[u] - 'a';

      int old = last[c];

      if (old != -1)
        newParent[u] = old;
      else
        newParent[u] = parent[u];

      last[c] = u;

      for (int v : tree[u])
        build(v);

      last[c] = old;
    };

    build(0);

    vector<vector<int>> newTree(n);

    for (int i = 1; i < n; i++)
      newTree[newParent[i]].push_back(i);

    vector<int> ans(n);

    function<int(int)> dfs = [&](int u) {
      int sz = 1;

      for (int v : newTree[u])
        sz += dfs(v);

      return ans[u] = sz;
    };

    dfs(0);

    return ans;
  }
};
