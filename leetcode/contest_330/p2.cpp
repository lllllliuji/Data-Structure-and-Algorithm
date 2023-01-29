class Solution {
   public:
    typedef long long ll;

    ll ppow(ll x, ll y, ll mod) {
        ll ans = 1;
        for (x %= mod; y; y >>= 1, x = x * x % mod)
            if (y & 1) ans = ans * x % mod;
        return ans;
    }
    int monkeyMove(int n) {
        int mod = 1e9 + 7;
        int x = ppow(2, n, mod);
        return (x - 2 + mod) % mod;
    }
};