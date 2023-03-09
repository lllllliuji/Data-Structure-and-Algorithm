
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
    string str;
    cin >> n >> str;
    vector<int> nums(n);
    vector<int> sum(n + 1);
    for (int i = 0; i < n; i++) {
        nums[i] = str[i] - '0';
        sum[i + 1] = sum[i] + nums[i];
    }
    long long ans = 0;
    unordered_map<int, int> hash;
    hash[0] = 1;
    for (int i = 0; i < n; i++) {
        int x = sum[i + 1] - (i + 1);
        ans += hash[x];
        hash[x] ++;
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