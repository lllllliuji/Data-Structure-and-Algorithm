class Solution {
   public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        vector<int> ans;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < n; i++) {
            int x = 0;
            for (int j = 0; j < m; j++) {
                string s = to_string(grid[j][i]);
                int t = s.size();
                x = max(x, t);
            }
            ans.push_back(x);
        }
        return ans;
    }
};