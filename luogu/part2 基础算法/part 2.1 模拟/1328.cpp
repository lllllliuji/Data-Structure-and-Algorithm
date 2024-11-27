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

int score(int x, int y) {
    if (x > y) return -score(y, x);
    if (x == 0) {
        if (y == 1 || y == 4) return -1;
        if (y == 2 || y == 3) return 1;
     }
    if (x == 1) {
        if (y == 2 || y == 4) return -1;
        if (y == 3) return 1;
    }
    if (x == 2) {
        if (y == 3) return -1;
        if (y == 4) return 1;
    }
    if (x == 3) {
        if (y == 4) return 1;
    }
     return 0;
}

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> pattern_a(a);
    vector<int> pattern_b(b);
    for (int i = 0; i < a; i++) cin >> pattern_a[i];
    for (int i = 0; i < b; i++) cin >> pattern_b[i];
    int score_a = 0, score_b = 0;
    for (int i = 0; i < n; i++) {
        int v = score(pattern_a[i % a], pattern_b[i % b]);
        score_a += max(v, 0);
        score_b -= min(v, 0);
    }
    cout << score_a << " " << score_b;
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