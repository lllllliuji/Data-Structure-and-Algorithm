class Solution {
   public:
    int minimumTotalPrice(int n, vector<vector<int>>& edges, vector<int>& price, vector<vector<int>>& trips) {
        vector<vector<int>> g(n);
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        vector<int> cnt(n);
        for (auto& trip : trips) {
            int start = trip[0], end = trip[1];
            function<bool(int, int)> dfs = [&](int u, int fa) -> bool {
                if (u == end) {
                    cnt[u]++;
                    return true;
                }
                for (int v : g[u]) {
                    if (v != fa && dfs(v, u)) {
                        cnt[u]++;
                        return true;
                    }
                }
                return false;
            };
            dfs(start, -1);
        }
        function<vector<int>(int, int)> solve = [&](int u, int fa) -> vector<int> {
            int x = cnt[u] * price[u];
            int y = cnt[u] * price[u] / 2;
            for (int v : g[u]) {
                if (v != fa) {
                    auto t = solve(v, u);
                    x += min(t[0], t[1]);
                    y += t[0];
                }
            }
            return {x, y};
        };
        auto t = solve(0, -1);
        return min(t[0], t[1]);
    }
};