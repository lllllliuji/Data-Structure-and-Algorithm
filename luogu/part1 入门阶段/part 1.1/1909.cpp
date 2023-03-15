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
    vector<pair<int, int>> arr;
    for (int i = 0; i < 3; i++) {
        int cnt, price;
        cin >> cnt >> price;
        arr.push_back({cnt, price});
    }
    int ans = 1e8;
    for (int i = 0; i < 3; i++) {
        int t = n;
        int cost = 0;
        while (t > 0) {
            t -= arr[i].first;
            cost += arr[i].second;
        }
        ans = min(ans, cost);
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