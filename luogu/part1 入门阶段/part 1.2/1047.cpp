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
    int l, m;
    cin >> l >> m;
    vector<pair<int, int>> arr;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        arr.push_back({a, b});
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < m; i++) {
        int left = arr[i].first, right = arr[i].second;
        while (i + 1 < m && right >= arr[i + 1].first) {
            right = max(right, arr[i + 1].second);
            i++;
        }
        l -= (right - left + 1);
    }
    cout << l + 1 << endl;
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