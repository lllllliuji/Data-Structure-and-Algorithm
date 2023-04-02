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
    int n;
    cin >> n;
    vector<int> f(n + 1);
    int ans = 0;
    function<int(int)> dfs = [&](int u) {
        if (f[u] != 0) return f[u];
        int cnt = 0;
        for (int i = 1; i <= u / 2; i++) {
            cnt += dfs(i);
        }
        return f[u] = cnt + 1;
    };
    cout << dfs(n) << endl;
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