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

bool check(int x) {
    for (int i = 2; i <= x / i; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int cnt = 0;
    function<void(int, int, int)> dfs = [&](int u, int c, int sum) {
        if (c == 0) {
            if (check(sum)) cnt++;
            return;
        }
        if (u >= n) {
            return;
        }
        // cout << u << " " << c << " " << sum << endl;
        dfs(u + 1, c, sum);
        dfs(u + 1, c - 1, sum + arr[u]);
    };
    dfs(0, k, 0);
    cout << cnt << endl;
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