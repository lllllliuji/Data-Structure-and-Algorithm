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
    int n, m;
    cin >> n >> m;
    vector<int> candy(n);
    vector<long long> p(m);
    vector<long long> sum(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> candy[i];
    }
    sort(candy.begin(), candy.end());
    for (int i = 0; i < n; i++) {
        p[i % m] += candy[i];
        sum[i] = p[i % m];
    }
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += sum[i];
        cout << cnt << " ";
    }
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