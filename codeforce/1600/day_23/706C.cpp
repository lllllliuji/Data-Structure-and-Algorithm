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
    int n;
    cin >> n;
    vector<int> cost(n);
    vector<string> strs(n);
    vector<string> h(n);
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> strs[i];
        h[i] = strs[i];
        reverse(h[i].begin(), h[i].end());
    }
    const long long INF = 1e18;
    vector<vector<long long>> f(n + 1, vector<long long>(2, INF));
    f[0][0] = f[0][1] = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            f[i + 1][0] = 0;
            f[i + 1][1] = cost[i];
            continue;
        }
        bool flag = false;
        if (strs[i] >= strs[i - 1]) {
            flag = true;
            f[i + 1][0] = min(f[i + 1][0], f[i][0]);
        }
        if (strs[i] >= h[i - 1]) {
            flag = true;
            f[i + 1][0] = min(f[i + 1][0], f[i][1]);
        }
        if (h[i] >= strs[i - 1]) {
            flag = true;
            f[i + 1][1] = min(f[i + 1][1], f[i][0] + cost[i]);
        }
        if (h[i] >= h[i - 1]) {
            flag = true;
            f[i + 1][1] = min(f[i + 1][1], f[i][1] + cost[i]);
        }
        if (!flag) {
            cout << -1 << endl;
            return;
        }
    }
    cout << (min(f[n][0], f[n][1]) == INF ? -1 : min(f[n][0], f[n][1])) << endl;
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