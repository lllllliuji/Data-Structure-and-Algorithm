class Solution {
   public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int m = robot.size(), n = factory.size();
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        long long INF = LONG_MAX / 3;
        vector<int> sum(n + 1);
        // dis[i][j] 前 j 个机器人到第 i 座工厂的距离之和
        vector<vector<long long>> dis(n + 1, vector<long long>(m + 1));
        vector<vector<long long>> f(n + 1, vector<long long>(m + 1, INF));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dis[i + 1][j + 1] = dis[i + 1][j] + abs(factory[i][0] - robot[j]);
            }
        }
        for (int i = 0; i <= n; i++) f[i][0] = 0;
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + factory[i][1];
            for (int j = 0; j < min(m, sum[i + 1]); j++) {
                f[i + 1][j + 1] = f[i][j + 1];
                for (int k = 0; k <= min(j + 1, factory[i][1]); k++) {
                    f[i + 1][j + 1] = min(f[i + 1][j + 1], f[i][j - k + 1] + dis[i + 1][j + 1] - dis[i + 1][j - k + 1]);
                }
            }
        }
        return f[n][m];
    }
};