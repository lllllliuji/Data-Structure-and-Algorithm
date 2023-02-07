class Solution {
   public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        priority_queue<int, vector<int>, less<int>> q[m];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                q[i].push(grid[i][j]);
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x = -1;
            for (int j = 0; j < m; j++) {
                auto t = q[j].top();
                q[j].pop();
                x = max(x, t);
            }
            ans += x;
        }
        return ans;
    }
};