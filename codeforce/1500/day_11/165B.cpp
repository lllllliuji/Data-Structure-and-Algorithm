#include <algorithm>
#include <functional>
// #include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    int l = 0, r = 1e9;
    while (l < r) {
        int mid = l + r >> 1;
        long long sum = 0;
        int x = mid;
        while (x) {
            sum += x;
            x /= k;
        }
        if (sum >= n)
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << endl;
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