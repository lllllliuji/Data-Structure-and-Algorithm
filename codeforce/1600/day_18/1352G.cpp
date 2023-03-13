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
    if (n <= 3)
        cout << -1 << endl;
    else {
        int i;
        for (i = 2; i <= n; i += 2) cout << i << ' ';
        if (n & 1) {
            i = n - 4;
            cout << i << ' ' << i + 4 << ' ' << i + 2 << ' ';
            i -= 2;
        } else {
            i = n - 3;
            cout << i << ' ' << i + 2 << ' ';
            i -= 2;
        }
        while (i >= 1) cout << i << ' ', i -= 2;
        cout << endl;
    }
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