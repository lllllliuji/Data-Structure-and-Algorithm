class Solution {
   public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        int n = types.size();
        vector<vector<long long>> f(n + 1, vector<long long>(target + 1));
        int mod = 1e9 + 7;
        f[0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= types[i][0]; j++) {
                for (int v = 0; v <= target; v++) {
                    if (v - j * types[i][1] >= 0) {
                        f[i + 1][v] += f[i][v - j * types[i][1]];
                    }
                    f[i + 1][v] %= mod;
                }
            }
        }
        return f[n][target] % mod;
    }
};