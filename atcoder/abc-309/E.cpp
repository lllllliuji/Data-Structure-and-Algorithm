#include <algorithm>
#include <functional>
// #include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1, vector<int>());
    unordered_map<int, int> hash;
    for (int i = 2; i <= n; i++) {
        int p;
        cin >> p;
        g[p].push_back(i);
    }
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        hash[x] = max(hash[x], y);
    }
    vector<bool> vis(n + 1, false);
    vector<bool> insured(n + 1, false);
    function<void(int, int)> dfs = [&](int u, int depth) {
        vis[u] = true;
        if (depth > 0 || hash[u] > 0) {
            insured[u] = true;
        }
        for (int v : g[u]) {
            if (!vis[v]) {
                dfs(v, max(depth - 1, hash[u]));
            }
        }
    };
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i, 0);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += insured[i];
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
    // cout << setprecision(10) << fixed;
    solve();
    return 0;
}