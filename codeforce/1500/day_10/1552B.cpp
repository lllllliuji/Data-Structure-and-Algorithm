#include <algorithm>
#include <functional>
// #include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

const int N = 50010;

int g[N][6];

bool check(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 5; i++) {
        if (g[x][i] < g[y][i]) cnt++;
    }
    return cnt >= 3;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> g[i][j];
        }
    }
    int ans = 1;
    for (int i = 2; i <= n; i++) {
        if (check(i, ans)) ans = i;
    }
    for (int i = 1; i <= n; i++) {
        if (ans != i) {
            if (!check(ans, i)) {
                cout << -1 << endl;
                return;
            }
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
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}