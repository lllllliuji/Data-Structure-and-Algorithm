class Solution {
   public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<vector<bool>> f(n, vector<bool>(n));
        for (int i = 0; i < n; i++) {
            f[i][i] = true;
        }
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    if (len <= 3)
                        f[i][j] = true;
                    else
                        f[i][j] = f[i + 1][j - 1];
                } else
                    f[i][j] = false;
            }
        }
        vector<int> g(n + 1);
        for (int i = 0; i < n; i++) {
            g[i + 1] = g[i];
            for (int j = i - k + 1; j >= 0; j--) {
                if (f[j][i]) {
                    // cout << j << " " << i << endl;
                    g[i + 1] = max(g[i + 1], 1 + g[j]);
                }
            }
        }
        return g[n];
    }
};