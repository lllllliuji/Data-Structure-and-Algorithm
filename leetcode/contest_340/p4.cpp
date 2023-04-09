class Solution {
   public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<vector<int>> q;
        q.push({0, 0, 1});
        const int inf = 0x3f3f3f3f;
        vector<vector<int>> dis(m, vector<int>(n, inf));
        dis[0][0] = 1;
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            int x = t[0], y = t[1], v = t[2];
            if (x == m - 1 && y == n - 1) {
                return dis[x][y];
            }
            if (v > dis[x][y]) continue;
            for (int i = min(m - 1, x + grid[x][y]); i > x; i--) {
                if (dis[i][y] > v + 1) {
                    dis[i][y] = v + 1;
                    q.push({i, y, v + 1});
                }
            }
            for (int j = min(n - 1, y + grid[x][y]); j > y; j--) {
                if (dis[x][j] > v + 1) {
                    dis[x][j] = v + 1;
                    q.push({x, j, v + 1});
                }
            }
        }
        return dis[m - 1][n - 1] == inf ? -1 : dis[m - 1][n - 1];
    }
};