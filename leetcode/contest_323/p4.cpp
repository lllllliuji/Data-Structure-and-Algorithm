class Solution {
   public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size();
        int k = queries.size();
        using E = pair<int, int>;
        priority_queue<E, vector<E>, greater<E>> q;
        q.push({grid[0][0], 0});
        grid[0][0] = -1;
        vector<int> idxs(k);
        for (int i = 0; i < k; i++) idxs[i] = i;
        sort(idxs.begin(), idxs.end(), [&](int a, int b) { return queries[a] < queries[b]; });
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};
        int cnt = 0;
        vector<int> ans(k);
        for (int i = 0; i < k; i++) {
            while (!q.empty() && queries[idxs[i]] > q.top().first) {
                auto t = q.top();
                q.pop();
                cnt++;
                int x = t.second / n, y = t.second % n;
                for (int j = 0; j < 4; j++) {
                    int a = x + dx[j];
                    int b = y + dy[j];
                    if (a >= 0 && a < m && b >= 0 && b < n && grid[a][b] != -1) {
                        q.push({grid[a][b], a * n + b});
                        grid[a][b] = -1;
                    }
                }
            }
            ans[idxs[i]] = cnt;
        }
        return ans;
    }
};