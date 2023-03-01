#include <algorithm>
#include <functional>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    function<double(int, int)> dfs = [&](int u, int fa) -> double {
        int sz = (g[u].size() - (fa != -1));
        double ans = 0.0;
        bool is_leaf = true;
        for (int x : g[u]) {
            if (x != fa) {
                ans += dfs(x, u) + 1;
                is_leaf = false;
            }
        }
        if (is_leaf) {
            return 0.0;
        }
        return ans / sz;
    };
    cout << dfs(1, -1) << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << setprecision(10) << fixed;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}