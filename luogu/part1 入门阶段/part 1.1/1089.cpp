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
    int a = 0, b = 0;
    for (int i = 1; i <= 12; i++) {
        int c;
        cin >> c;
        a += 300;
        if (a < c) {
            cout << -i << endl;
            return;
        }
        a -= c;
        b += 100 * (a / 100);
        a = a % 100;
    }
    cout << a + b * 1.2 << endl;
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