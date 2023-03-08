#include <algorithm>
#include <functional>
// #include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void solve() {
    int n, k, d;
    cin >> n >> k >> d;
    vector<vector<int>> f(n + 1, vector<int>(2));
    int mod = 1e9 + 7;
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= min(i, k); j++) {
            if (j >= d) {
                f[i][1] += (f[i - j][1] + f[i - j][0]) % mod;
            } else {
                f[i][0] += f[i - j][0];
                f[i][1] += f[i - j][1];
            }
            f[i][0] %= mod;
            f[i][1] %= mod;
        }
    }
    cout << f[n][1] << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin.tie(0);
    ios::sync_with_stdio(0);
    // cout << setprecision(10) << fixed;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}