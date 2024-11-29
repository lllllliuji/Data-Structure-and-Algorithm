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
    int n, m;
    cin >> n >> m;
    vector<pair<int, string>> person(n);
    for (int i = 0; i < n; i++) {
        cin >> person[i].first >> person[i].second;
    }
    int idx = 0;
    while (m--) {
        int d, cnt;
        cin >> d >> cnt;
        if (person[idx].first ^ d != 0) {
            idx = (idx + cnt) % n;
        } else {
            idx = (idx - cnt + n) % n;
        }
    }
    cout << person[idx].second << endl;
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