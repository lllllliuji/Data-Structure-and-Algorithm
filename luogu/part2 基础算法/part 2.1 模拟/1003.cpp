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

struct Point {
    int a, b;
    int x, y;
};
void solve() {
    int n;
    cin >> n;
    Point p[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i].a >> p[i].b >> p[i].x >> p[i].y;
        p[i].x += p[i].a;
        p[i].y += p[i].b;
    }
    int u, v;
    cin >> u >> v;
    for (int i = n - 1; i >= 0; i--) {
        if (u >= p[i].a && u <= p[i].x && v >= p[i].b && v <= p[i].y) {
            cout << i + 1 << endl;
            return;
        }
    }
    cout << -1 << endl;
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