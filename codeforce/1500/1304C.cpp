#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Customer {
    int t;
    int l, r;
    Customer(int a, int b, int c) : t(a), l(b), r(c) {}
};

void help(int l, int r, int u, int v, int& x, int& y, bool& success) {
    if (r < u || v < l) {
        success = false;
        return;
    }
    x = max(l, u);
    y = min(r, v);
}

void solve() {
    int n, l, r;
    cin >> n >> l;
    r = l;
    vector<Customer> vec;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        vec.emplace_back(a, b, c);
    }
    sort(vec.begin(), vec.end(),
         [](const auto& c1, const auto& c2) { return c1.t != c2.t ? (c1.t < c2.t) : (c1.l < c2.l); });
    int preT = 0;
    bool flag = true;
    for (int i = 0; i < n; i++) {
        bool success = true;
        help(l - (vec[i].t - preT), r + (vec[i].t - preT), vec[i].l, vec[i].r, l, r, success);
        if (!success) {
            flag = false;
            break;
        }
        preT = vec[i].t;
    }
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
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