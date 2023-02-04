class Solution {
   public:
    const int mod = 1e9 + 7;
    typedef long long ll;

    ll ppow(ll x, ll y, ll mod) {
        ll ans = 1;
        for (x %= mod; y; y >>= 1, x = x * x % mod)
            if (y & 1) ans = ans * x % mod;
        return ans;
    }
    int countPartitions(vector<int>& nums, int k) {
        long sum = accumulate(nums.begin(), nums.end(), 0LL);
        if (sum < 2 * k) return 0;
        int n = nums.size();
        vector<vector<long>> f(n + 1, vector<long>(k + 1));
        for (int i = 1; i <= k; i++) f[0][i] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                f[i + 1][j] = f[i][j];
                if (j - nums[i] >= 0) f[i + 1][j] += f[i][j - nums[i]];
                f[i + 1][j] = f[i + 1][j] % mod;
            }
        }
        long total = ppow(2, n, mod);
        return (total + mod - (2 * f[n][k]) % mod) % mod;
    }
};