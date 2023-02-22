#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    long long sum = accumulate(arr.begin(), arr.end(), 0LL);
    if (sum & 1) {
        cout << "NO" << endl;
        return;
    }
    int maxx = *max_element(arr.begin(), arr.end());
    if (2LL * maxx > sum) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    cin.tie(0);
    ios::sync_with_stdio(0);
    solve();
    // int t;
    // cin >> t;
    // while (t--) {
    //     solve();
    // }
    return 0;
}