class Solution {
   public:
    bool is_prime(char x) { return x == '2' || x == '5' || x == '7' || x == '3'; }
    int beautifulPartitions(string s, int k, int minLength) {
        if (!is_prime(s[0])) {
            return 0;
        }
        int n = s.size();
        int mod = 1e9 + 7;
        long f[n + 1][k + 1];
        long g[n + 1][k + 1];
        memset(f, 0, sizeof f);
        memset(g, 0, sizeof g);
        for (int i = 0; i <= n; i++) g[i][0] = 1;
        for (int i = 0; i < n; i++) {
            if (i >= minLength - 1 && !is_prime(s[i]) && (i == n - 1 || is_prime(s[i + 1]))) {
                for (int j = 1; j <= k; j++) {
                    f[i + 1][j] = g[i - minLength + 1][j - 1];
                }
            }
            for (int j = 1; j <= k; j++) {
                g[i + 1][j] = (g[i][j] + f[i + 1][j]) % mod;
            }
        }
        return f[n][k];
    }
};