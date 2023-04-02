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

int month[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
void solve() {
    int start, end;
    cin >> start >> end;
    int ans = 0;
    for (int i = 1; i <= 12; i++) {
        for (int j = 1; j <= month[i]; j++) {
            int x = (j % 10) * 1000 + (j / 10) * 100 + (i % 10) * 10 + (i / 10);
            int y = x * 10000 + i * 100 + j;
            if (y >= start && y <= end) ans++;
        }
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