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

int check(long long h, long long a, long long b) { return (h - 1) % (a + b) / a; }

void solve() {
    int n;
    long long a, b, k;
    cin >> n >> a >> b >> k;
    int ans = 0;
    vector<int> cost;
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;
        cost.push_back(check(h, a, b));
    }
    sort(cost.begin(), cost.end());
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        k -= cost[i];
        if (k < 0) break;
        cnt++;
    }
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