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
    int a = 1, b = 1;
    int x = -1, y = 1;
    for (int i = 1; i < n; i++) {
        a += x;
        b += y;
        if (a == 0) {
            a = 1;
            x = -x;
            y = -y;
        }
        if (b == 0) {
            b = 1;
            x = -x;
            y = -y;
        }
    }
    cout << a << "/" << b << endl;
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