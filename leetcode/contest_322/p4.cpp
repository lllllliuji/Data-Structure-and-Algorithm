class Solution {
   public:
    bool is_bipartite(int n, vector<vector<int>>& g) {
        int color[n + 1];
        memset(color, 0, sizeof color);
        function<bool(int, int, vector<vector<int>>&)> dfs = [&](int u, int c, vector<vector<int>>& g) -> bool {
            color[u] = c;
            for (int x : g[u]) {
                if (!color[x]) {
                    if (!dfs(x, 3 - c, g)) return false;
                } else if (color[x] == c) {
                    return false;
                }
            }
            return true;
        };
        bool flag = true;
        for (int i = 1; i <= n; i++) {
            if (!color[i]) {
                if (!dfs(i, 1, g)) {
                    flag = false;
                    break;
                }
            }
        }
        return flag;
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n + 1, vector<int>());
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        if (!is_bipartite(n, g)) {
            return -1;
        }
        vector<int> p(n + 1);
        vector<unordered_set<int>> group(n + 1, unordered_set<int>());
        for (int i = 1; i <= n; i++) {
            p[i] = i;
            group[i].insert(i);
        }
        function<int(int)> find = [&](int x) -> int { return x == p[x] ? p[x] : p[x] = find(p[x]); };
        auto unite = [&](int a, int b) {
            int fa = find(a), fb = find(b);
            if (fa != fb) {
                if (fa > fb) swap(fa, fb);
                p[fb] = fa;
                for (int k : group[fb]) group[fa].insert(k);
            }
        };
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            unite(a, b);
        }
        function<int(int)> bfs = [&](int u) -> int {
            vector<bool> vis(n + 1);
            queue<int> q;
            q.push(u);
            vis[u] = true;
            int depth = 0;
            while (!q.empty()) {
                int sz = q.size();
                while (sz--) {
                    auto t = q.front();
                    q.pop();
                    for (int v : g[t]) {
                        if (!vis[v]) {
                            q.push(v);
                            vis[v] = true;
                        }
                    }
                }
                depth++;
            }
            return depth;
        };
        int ans = 0;
        unordered_set<int> vis;
        for (int i = 1; i <= n; i++) {
            if (int root = find(i); !vis.count(root)) {
                int cnt = 0;
                for (int start : group[root]) {
                    cnt = max(cnt, bfs(start));
                }
                ans += cnt;
                vis.insert(root);
            }
        }
        return ans;
    }
};