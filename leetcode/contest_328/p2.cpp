class Solution {
   public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        int f[n + 10][n + 10];
        memset(f, 0, sizeof f);
        for (auto& q : queries) {
            int r1 = q[0], c1 = q[1], r2 = q[2], c2 = q[3];
            f[r1][c1]++;
            f[r2 + 1][c2 + 1]++;
            f[r1][c2 + 1]--;
            f[r2 + 1][c1]--;
        }
        for (int j = 1; j < n; j++) f[0][j] = f[0][j - 1] + f[0][j];
        for (int i = 1; i < n; i++) f[i][0] = f[i - 1][0] + f[i][0];
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < n; j++) {
                f[i][j] += f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
            }
        }
        vector<vector<int>> ans(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = f[i][j];
            }
        }

        return ans;
    }
};