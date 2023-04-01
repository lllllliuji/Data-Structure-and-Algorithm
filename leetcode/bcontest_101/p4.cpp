class Solution {
   public:
    int dijkstra(int a, int b, vector<unordered_set<int>>& g) {
        int n = g.size();
        vector<int> dis(n + 1, 0x3f3f3f3f);
        dis[a] = 0;
        using E = pair<int, int>;
        priority_queue<E, vector<E>, greater<>> q;
        q.push({0, a});
        while (!q.empty()) {
            auto t = q.top();
            q.pop();
            int du = t.first, u = t.second;
            if (dis[u] < du) {
                continue;
            }
            for (auto& e : g[u]) {
                int v = e, dv = du + 1;
                // int v = e.first, dv = e.second + du;
                if (dv < dis[v]) {
                    dis[v] = dv;
                    q.push({dv, v});
                }
            }
        }
        return dis[b] == 0x3f3f3f3f ? -1 : dis[b];
    }
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<unordered_set<int>> g(n, unordered_set<int>());
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].insert(b);
            g[b].insert(a);
        }
        int ans = 0x3f3f3f3f;
        for (auto& e : edges) {
            int a = e[0], b = e[1];
            g[a].erase(b);
            g[b].erase(a);
            int dis = dijkstra(a, b, g);
            if (dis != -1) {
                ans = min(ans, dis + 1);
            }
            // ans = min(ans, dijkstra(a, b, g) + 1);
            g[a].insert(b);
            g[b].insert(a);
        }
        return ans == 0x3f3f3f3f ? -1 : ans;
    }
};