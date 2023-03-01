#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    long long ans = 1;
    for (int i = 1; i <= n; ++i) {
        ans *= i;
        ans %= MOD;
    }
    long long temp = 1;
    for (int i = 0; i < n - 1; ++i) {
        temp *= 2;
        temp %= MOD;
    }
    ans = (ans - temp + MOD) % MOD;
    cout << ans << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}