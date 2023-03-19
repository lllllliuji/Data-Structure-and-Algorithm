class Solution {
   public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        unordered_map<int, pair<int, int>> hash;
        int m = grid.size(), n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                hash[grid[i][j]] = {i, j};
            }
        }

        int u = 0;
        bool flag = true;
        int x = 0, y = 0;
        for (int i = 1; i < m * n; i++) {
            int a = hash[i].first, b = hash[i].second;
            // cout << a << " " << b << endl;
            int dis = abs(a - x) + abs(b - y);
            if (dis != 3) {
                flag = false;
                break;
            }
            if (abs(a - x) == 2) {
                x = a;
                y = b;
            } else if (abs(b - y) == 2) {
                x = a;
                y = b;
            } else {
                flag = false;
            }
        }
        return flag;
    }
};