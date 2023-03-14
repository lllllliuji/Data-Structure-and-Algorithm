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
    using E = pair<int, int>;
    function<bool(E, E)> cmp = [](const auto& pa, const auto& pb) {
        int lena = pa.second - pa.first + 1;
        int lenb = pb.second - pb.first + 1;
        return lena == lenb ? pa.first > pb.first : lena < lenb;
    };
    priority_queue<E, vector<E>, decltype(cmp)> q(cmp);
    q.push({0, n - 1});
    vector<int> ans(n);
    int round = 1;
    while (!q.empty()) {
        auto [l, r] = q.top();
        q.pop();
        int mid = (l + r - ((r - l + 1) % 2 == 0)) / 2;
        ans[mid] = round++;
        if (l < mid) q.push({l, mid - 1});
        if (r > mid) q.push({mid + 1, r});
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
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
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}