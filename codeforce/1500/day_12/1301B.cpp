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
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    function<int(int)> check = [&](int k) -> int {
        int ret = 0;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] == -1 && arr[i + 1] == -1) {
                ret = max(ret, 0);
            } else if (arr[i] == -1) {
                ret = max(ret, abs(arr[i + 1] - k));
            } else if (arr[i + 1] == -1) {
                ret = max(ret, abs(arr[i] - k));
            } else {
                ret = max(ret, abs(arr[i] - arr[i + 1]));
            }
        }
        return ret;
    };
    int l = 0, r = 1e9;
    while (l < r) {
        int delta = (r - l) / 3;
        int low = l + delta, high = r - delta;
        if (check(low) < check(high)) {
            r = high - 1;
        } else
            l = low + 1;
    }
    cout << check(l) << " " << l << endl;
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