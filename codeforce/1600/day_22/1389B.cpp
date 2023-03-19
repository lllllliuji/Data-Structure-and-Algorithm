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

const int N = 100010;

int arr[N];

void solve() {
    int n, k, x;
    cin >> n >> k >> x;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int ans = 0;
    int sum = 0;
    int mx = 0;
    for (int i = 0; i <= k; i++) {
        if (i < n - 1) {
            mx = max(mx, arr[i] + arr[i + 1]);
        }
        sum += arr[i];
        if (i % 2 == k % 2) {
            int cnt = (k - i) / 2;
            ans = max(ans, sum + min(cnt, x) * mx);
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