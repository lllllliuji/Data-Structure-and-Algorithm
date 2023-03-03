#include <algorithm>
#include <functional>
// #include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> freq;
    unordered_map<int, int> hash;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        hash[num]++;
    }
    for (auto i : hash) {
        freq.push_back(i.second);
    }
    sort(freq.begin(), freq.end());
    int ans = n;
    for (int i = 0; i < freq.size(); ++i) {
        int c = freq[i];
        int number = freq.size() - i;
        int remaining = c * number;
        int removed = n - remaining;
        ans = min(ans, removed);
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