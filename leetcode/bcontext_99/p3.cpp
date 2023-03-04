class Solution {
   public:
    int p[100010];
    void init(int n) {
        for (int i = 0; i < n; i++) {
            p[i] = i;
        }
    }
    int find(int x) { return x == p[x] ? p[x] : p[x] = find(p[x]); }
    void unite(int a, int b) {
        int fa = find(a), fb = find(b);
        p[fb] = fa;
    }
    typedef long long ll;
    ll ppow(ll x, ll y, ll mod) {
        ll ans = 1;
        for (x %= mod; y; y >>= 1, x = x * x % mod)
            if (y & 1) ans = ans * x % mod;
        return ans;
    }
    int countWays(vector<vector<int>>& ranges) {
        int n = ranges.size();
        init(n);
        sort(ranges.begin(), ranges.end());
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int l = ranges[i][0], r = ranges[i][1];
            while (i + 1 < n && r >= ranges[i + 1][0]) {
                r = max(r, ranges[i + 1][1]);
                unite(i, i + 1);
                i++;
            }
            cnt++;
        }
        unordered_set<int> S;
        for (int i = 0; i < n; i++) {
            S.insert(find(i));
        }
        int x = S.size();
        int mod = 1e9 + 7;
        return ppow(2, cnt, mod);
    }
};