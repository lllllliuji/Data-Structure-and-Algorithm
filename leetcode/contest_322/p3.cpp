class Solution {
   public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<int> p(n + 1);
        vector<int> sz(n + 1, INT_MAX);
        for (int i = 1; i <= n; i++) p[i] = i;
        function<int(int)> find = [&](int x) -> int { return x == p[x] ? p[x] : p[x] = find(p[x]); };
        auto unite = [&](int a, int b, int w) {
            int fa = find(a);
            int fb = find(b);
            p[fa] = fb;
            sz[fb] = min({sz[fb], sz[fa], w});
        };

        for (auto& r : roads) {
            int a = r[0], b = r[1], w = r[2];
            unite(a, b, w);
        }
        return sz[find(1)];
    }
};