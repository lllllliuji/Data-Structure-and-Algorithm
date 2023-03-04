class Solution {
   public:
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        int n = edges.size();

        auto get = [](int fa, int sn) -> string { return to_string(fa) + "_" + to_string(sn); };
        vector<vector<int>> g(n + 1, vector<int>());
        unordered_map<string, int> hash;
        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        for (auto& e : guesses) {
            hash[get(e[0], e[1])]++;
        }
        int F = 0;
        function<void(int, int)> dfs1 = [&](int sn, int fa) {
            if (fa >= 0) F += hash[get(fa, sn)];
            for (int x : g[sn]) {
                if (x != fa) dfs1(x, sn);
            }
        };
        dfs1(0, -1);
        int ans = 0;
        function<void(int, int)> dfs2 = [&](int sn, int fa) {
            if (F >= k) ans++;
            for (int x : g[sn]) {
                if (x != fa) {
                    F -= hash[get(sn, x)];
                    F += hash[get(x, sn)];
                    dfs2(x, sn);
                    F -= hash[get(x, sn)];
                    F += hash[get(sn, x)];
                }
            }
        };
        dfs2(0, -1);
        return ans;
    }
};