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
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++) {
        int coe;
        cin >> coe;
        if (coe == 0) continue;
        if (coe < 0) {
            if (coe == -1 && i < n)
                cout << "-";
            else
                cout << coe;
        } else {
            if (i > 0) cout << "+";
            if (coe != 1 || i == n) cout << coe;
        }
        if (i < n) {
            cout << "x";
            if (n - i > 1) cout << "^" << n - i;
        }
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
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}