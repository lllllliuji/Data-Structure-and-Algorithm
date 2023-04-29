class Solution {
   public:
    int t[100010];
    int lowbit(int x) { return x & -x; }

    int query(int x) {
        int ans = 0;
        for (int i = x; i; i -= lowbit(i)) ans += t[i];
        return ans;
    }

    void add(int x, int c) {
        for (int i = x; i <= n; i += lowbit(i)) t[i] += c;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        function<int(int, int)> dfs = [&](int x, int y) -> int {
            if (grid[x][y] == 0) return 0;
            int v = grid[x][y];
            grid[x][y] = 0;
            for (int i = 0; i < 4; i++) {
                int a = x + dx[i];
                int b = y + dy[i];
                if (a >= 0 && a < m && b >= 0 && b < n) {
                    v += dfs(a, b);
                }
            }
            return v;
        };
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, dfs(i, j));
            }
        }
        return ans;
    }
};