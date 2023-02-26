class Solution {
   public:
    int minimumTime(vector<vector<int>>& grid) {
        if (grid[0][1] > 1 && grid[1][0] > 1) {
            return -1;
        }
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vector<vector<int>> f(m, vector<int>(n, 0x3f3f3f3f));
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        using E = pair<int, int>;
        priority_queue<E, vector<E>, greater<E>> q;
        q.push({0, 0});
        vis[0][0] = true;
        f[0][0] = 0;
        while (!q.empty()) {
            auto [time, pos] = q.top();
            int x = pos / n, y = pos % n;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int a = x + dx[i];
                int b = y + dy[i];
                if (a >= 0 && a < m && b >= 0 && b < n && !vis[a][b]) {
                    int diff = grid[a][b] - f[x][y];
                    if (diff <= 0) {
                        f[a][b] = f[x][y] + 1;
                    } else {
                        f[a][b] = (diff & 1) ? grid[a][b] : grid[a][b] + 1;
                    }
                    q.push({f[a][b], a * n + b});
                    vis[a][b] = true;
                }
            }
        }
        return vis[m - 1][n - 1] ? f[m - 1][n - 1] : -1;
    }
};