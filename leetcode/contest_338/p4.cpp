class Solution {
   public:
    int collectTheCoins(vector<int> &coins, vector<vector<int>> &edges) {
        int n = coins.size();
        vector<vector<int>> g(n);
        vector<int> deg(n);
        for (auto &e : edges) {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);  // 建图
            ++deg[x];
            ++deg[y];
        }

        // 用拓扑排序「剪枝」：去掉没有金币的子树
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            // 无金币叶子
            if (deg[i] == 1 && coins[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int y : g[x])
                if (--deg[y] == 1 && coins[y] == 0) q.push(y);
        }

        // 再次拓扑排序
        for (int i = 0; i < n; ++i)
            if (deg[i] == 1 && coins[i])  // 有金币叶子
                q.push(i);
        if (q.size() <= 1) return 0;  // 至多一个有金币的叶子，直接收集
        int time[n];
        memset(time, 0, sizeof(time));
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int y : g[x])
                if (--deg[y] == 1) {
                    time[y] = time[x] + 1;  // 记录入队时间
                    q.push(y);
                }
        }

        int ans = 0;
        for (auto &e : edges)
            if (time[e[0]] >= 2 && time[e[1]] >= 2) ans += 2;
        return ans;
    }
};