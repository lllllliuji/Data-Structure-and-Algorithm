#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    vector<int> x, y;
    for (int i = 0, j = 0; i < n && j < m; i++) {
        if (s[i] == t[j]) {
            x.push_back(i);
            j++;
        }
    }
    for (int i = n - 1, j = m - 1; i >= 0 && j >= 0; i--) {
        if (s[i] == t[j]) {
            y.push_back(i);
            j--;
        }
    }
    reverse(y.begin(), y.end());
    int ans = 0;
    for (int i = 0; i < m - 1; i++) {
        ans = max(ans, abs(x[i] - y[i + 1]));
    }
    cout << ans << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}