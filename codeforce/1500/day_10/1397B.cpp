#include <algorithm>
#include <functional>
// #include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    long long ans = LLONG_MAX, store, temp, limit = 1e14;
    for (int i = 1, ok;; i++) {
        temp = 1;
        store = 0;
        ok = 1;
        for (int j = 0; j < n; j++) {
            store += abs(temp - a[j]);
            if (store > limit) {
                ok = 0;
                break;
            }
            temp *= i;
        }
        if (ok)
            ans = min(ans, store);
        else
            break;
    }
    cout << ans << '\n';
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