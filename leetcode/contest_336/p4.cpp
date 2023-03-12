class Solution {
   public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](const auto& a, const auto& b) { return a[1] < b[1]; });
        int ans = 0;
        vector<bool> run(2001);
        for (const auto& t : tasks) {
            int l = t[0], r = t[1], c = t[2];
            for (int i = l; i <= r; i++) {
                if (run[i]) c--;
            }
            for (int i = r; c > 0; i--) {
                if (!run[i]) {
                    run[i] = true;
                    c--;
                    ans++;
                }
            }
        }
        return ans;
    }
};

class Solution {
   public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        int mx = 0;
        for (auto& vec : tasks) mx = max(mx, vec[1]);

        vector<int> e[mx + 2], v[mx + 2];
        // 第一个不等式
        for (int i = 1; i <= mx; i++) {
            e[i].push_back(i - 1);
            v[i].push_back(0);
        }
        // 第二个不等式
        for (int i = 0; i < mx; i++) {
            e[i].push_back(i + 1);
            v[i].push_back(1);
        }
        // 第三个不等式
        for (auto& vec : tasks) {
            e[vec[1]].push_back(vec[0] - 1);
            v[vec[1]].push_back(-vec[2]);
        }

        // 差分约束要建立超级源点
        int S = mx + 1;
        for (int i = 0; i <= mx; i++) {
            e[S].push_back(i);
            v[S].push_back(0);
        }

        // SPFA
        const int INF = 1e9;
        queue<int> q;
        int dis[mx + 2];
        for (int i = 0; i <= mx + 1; i++) dis[i] = INF;
        bool vis[mx + 2];
        memset(vis, 0, sizeof(vis));

        q.push(S);
        dis[S] = 0;
        vis[S] = true;
        while (!q.empty()) {
            int sn = q.front();
            q.pop();
            vis[sn] = false;
            for (int i = 0; i < e[sn].size(); i++) {
                int fn = e[sn][i], val = v[sn][i];
                if (dis[fn] <= dis[sn] + val) continue;
                dis[fn] = dis[sn] + val;
                if (vis[fn]) continue;
                q.push(fn);
                vis[fn] = true;
            }
        }

        return dis[mx] - dis[0];
    }
};
