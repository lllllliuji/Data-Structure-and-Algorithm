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

vector<int> solve3(int n) {
    if (n % 2 == 1) return {1, n / 2, n / 2};
    if (n % 4 == 0) return {n / 2, n / 4, n / 4};
    if (n % 2 == 0) return {2, n / 2 - 1, n / 2 - 1};
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> added = solve3(n - k + 3);
    for (int i = 0; i < k; ++i) {
        cout << (i < 3 ? added[i] : 1) << ' ';  // <3
    }
    cout << '\n';
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