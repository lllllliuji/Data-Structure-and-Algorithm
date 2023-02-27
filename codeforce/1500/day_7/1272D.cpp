#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    vector<int> f(n + 1, 0);
    vector<int> g(n + 1, 0);
    f[0] = 1;
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            f[i] = f[i - 1] + 1;
        } else {
            f[i] = 1;
        }
        ans = max(ans, f[i]);
    }
    g[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] < arr[i + 1]) {
            g[i] = g[i + 1] + 1;
        } else {
            g[i] = 1;
        }
    }
    for (int i = 1; i < n - 1; i++) {
        if (arr[i - 1] < arr[i + 1]) {
            ans = max(ans, f[i - 1] + g[i + 1]);
        }
    }
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