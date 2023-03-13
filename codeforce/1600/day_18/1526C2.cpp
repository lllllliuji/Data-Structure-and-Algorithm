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
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    priority_queue<int, vector<int>, greater<int>> q;
    long long h = 0;
    for (int i = 1; i <= n; i++) {
        if (h + p[i] >= 0) {
            q.push(p[i]);
            h += p[i];
        } else if (!q.empty() && p[i] > q.top()) {
            h += p[i] - q.top();
            q.pop();
            q.push(p[i]);
        }
    }
    cout << q.size() << endl;
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