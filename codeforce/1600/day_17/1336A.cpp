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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> g(n + 1, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> v(n + 1);
    function<int(int, int, int)> dfs = [&](int sn, int fa, int depth) -> int {
        int cnt = 0;
        for (int x : g[sn]) {
            if (x != fa) {
                cnt += dfs(x, sn, depth + 1);
            }
        }
        v[sn] = depth - cnt;
        return cnt + 1;
    };
    dfs(1, 0, 0);
    sort(v.begin() + 1, v.end());
    long long ans = 0;
    for (int i = 0; i < k; i++) {
        ans += v[n - i];
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
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}