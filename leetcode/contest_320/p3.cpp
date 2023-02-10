class Solution {
   public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        unordered_map<int, vector<int>> g;
        for (auto& road : roads) {
            g[road[0]].push_back(road[1]);
            g[road[1]].push_back(road[0]);
        }
        long long ans = 0;
        unordered_set<int> vis;
        function<int(int, int)> dfs = [&](int sn, int fa) -> int {
            int cnt = 1;
            for (int x : g[sn]) {
                if (x != fa) {
                    int t = dfs(x, sn);
                    ans += (t + seats - 1) / seats;
                    cnt += t;
                }
            }
            return cnt;
        };
        dfs(0, -1);
        return ans;
    }
};