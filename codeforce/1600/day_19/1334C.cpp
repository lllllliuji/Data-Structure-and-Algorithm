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
    using E = pair<long long, long long>;
    vector<E> arr;
    for (int i = 0; i < n; i++) {
        long long a, b;
        cin >> a >> b;
        arr.push_back({a, b});
    }
    vector<long long> c(n);
    for (int i = 0; i < n; i++) {
        c[i] = max(0LL, arr[i].first - arr[(i + n - 1) % n].second);
    }
    long long sum = accumulate(c.begin(), c.end(), 0LL);
    long long ans = 1e18;
    for (int i = 0; i < n; i++) {
        ans = min(ans, sum - c[i] + arr[i].first);
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
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}