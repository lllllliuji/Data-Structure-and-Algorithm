class Solution {
   public:
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        vector<vector<int>> g(n, vector<int>());
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        long long ans = 0;
        function<pair<long long, long long>(int, int)> dfs = [&](int u, int fa) -> pair<long long, long long> {
            long long p = price[u], has_leaf = p, no_leaf = 0;
            for (int v : g[u]) {
                if (v != fa) {
                    auto [h, n] = dfs(v, u);
                    ans = max({ans, has_leaf + n, no_leaf + h});
                    has_leaf = max(has_leaf, h + p);
                    no_leaf = max(no_leaf, n + p);
                }
            }
            return {has_leaf, no_leaf};
        };
        dfs(0, -1);
        return ans;
    }
};