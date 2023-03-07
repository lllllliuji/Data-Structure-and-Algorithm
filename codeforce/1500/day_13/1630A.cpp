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
    vector<int> ans(n);
    iota(ans.begin(), ans.end(), 0);
    if (n == 4 && k == 3) {
        cout << -1 << endl;
        return;
    }
    if (k == n - 1) {
        swap(ans[0], ans[n - 2]);
        swap(ans[n - 2], ans[n - 3]);
    } else {
        swap(ans[0], ans[k]);
    }
    for (int i = 0; i < n / 2; i++) {
        cout << ans[i] << " " << ans[n - i - 1] << endl;
    }
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin.tie(0);
    ios::sync_with_stdio(0);
    // cout << setprecision(10) << fixed;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}