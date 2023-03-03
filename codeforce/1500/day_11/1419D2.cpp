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
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    vector<int> ans;
    for (int i = 0, j = n / 2; i < n / 2 || j < n; i++, j++) {
        if (j < n) ans.push_back(arr[j]);
        if (i < n / 2) ans.push_back(arr[i]);
    }
    int cnt = 0;
    for (int i = 1; i < n - 1; i++) {
        if (ans[i] < ans[i - 1] && ans[i] < ans[i + 1]) cnt ++;
    }
    cout << cnt << endl;
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;
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