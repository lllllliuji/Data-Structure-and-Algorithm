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
    int arr[10];
    int mx = -1;
    for (int i = 1; i <= 7; i++) {
        int a, b;
        cin >> a >> b;
        arr[i] = a + b;
        mx = max(mx, arr[i]);
    }
    if (mx > 8) {
        for (int i = 1; i <= 7; i++) {
            if (arr[i] == mx) {
                cout << i << endl;
                return;
            }
        }
    }
    cout << 0 << endl;
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