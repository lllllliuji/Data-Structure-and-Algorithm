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
int ans;
void dfs(int v, int cnt, int start) {
    if (cnt == 0) {
        if (v == 0) ans++;
        return;
    }
    if (v < start) {
        return;
    }
    for (int i = start; i <= v / cnt; i++) {
        dfs(v - i, cnt - 1, i);
    }
}
void solve() {
    int n, k;
    cin >> n >> k;
    dfs(n, k, 1);
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