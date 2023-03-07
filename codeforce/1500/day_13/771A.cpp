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
    vector<int> p(n + 1);
    vector<int> sz(n + 1);
    vector<int> d(n + 1);
    for (int i = 1; i <= n; i++) {
        p[i] = i;
        sz[i] = 1;
    }
    function<int(int)> find = [&](int x) -> int { return x == p[x] ? p[x] : p[x] = find(p[x]); };
    function<void(int, int)> unite = [&](int a, int b) {
        int fa = find(a), fb = find(b);
        if (fa > fb) swap(fa, fb);
        if (fa != fb) {
            p[fb] = fa;
            sz[fa] += sz[fb];
        }
    };
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        unite(a, b);
        d[a]++;
        d[b]++;
    }
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        if (d[i] != sz[find(i)] - 1) {
            flag = false;
            break;
        }
    }
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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