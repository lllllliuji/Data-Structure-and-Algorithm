#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    int zeros = 0, positive = 0, negative = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        zeros += (arr[i] - k) == 0;
    }
    long long sum = accumulate(arr.begin(), arr.end(), 0LL);
    if (zeros == n) {
        cout << "0" << endl;
    } else if (sum == n * k || zeros != 0) {
        cout << "1" << endl;
    } else {
        cout << "2" << endl;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}