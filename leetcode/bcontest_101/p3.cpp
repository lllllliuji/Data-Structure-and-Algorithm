class Solution {
   public:
    long long makeSubKSumEqual(vector<int>& arr, int k) {
        int n = arr.size();
        vector<bool> vis(n);
        vector<vector<int>> g;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            vector<int> v;
            int x = i;
            while (!vis[x]) {
                vis[x] = true;
                v.push_back(arr[x]);
                x = (x + k) % n;
            }
            sort(v.begin(), v.end());
            g.push_back(v);
        }
        long long ans = 0;
        for (int i = 0; i < g.size(); i++) {
            int m = g[i].size();
            if (m & 1) {
                for (int j = 0; j < g[i].size(); j++) {
                    ans += abs(g[i][j] - g[i][m / 2]);
                }
            } else {
                long long v1 = 0;
                long long v2 = 0;
                for (int j = 0; j < g[i].size(); j++) {
                    v1 += abs(g[i][j] - g[i][m / 2]);
                }
                for (int j = 0; j < g[i].size(); j++) {
                    v2 += abs(g[i][j] - g[i][(m / 2) - 1]);
                }
                ans += min(v1, v2);
            }
        }
        return ans;
    }
};